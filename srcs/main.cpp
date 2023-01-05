/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:41:56 by dhubleur          #+#    #+#             */
/*   Updated: 2023/01/05 14:54:27 by dhubleur         ###   ########.fr       */
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
	(void)p;
	return (0);
}