/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:41:56 by dhubleur          #+#    #+#             */
/*   Updated: 2023/01/05 16:21:24 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Polynom.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./computor <equation>" << std::endl;
		return (1);
	}
	Polynom p = Polynom(std::string(argv[1]));
	if (!p.isValid())
		return (1);
	p.reduce();
	std::cout << "Reduced form: ";
	p.print();
	std::cout << "Poylnomial degree: " << p.getDegree() << std::endl;
	if (p.getDegree() > 2)
	{
		std::cerr << "The polynomial degree is stricly greater than 2, I can't solve." << std::endl;
		return (1);
	}
	return (0);
}