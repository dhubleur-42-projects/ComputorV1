/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:41:56 by dhubleur          #+#    #+#             */
/*   Updated: 2023/02/20 17:01:31 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Polynom.hpp"
#include "SecondDegreeEquation.hpp"
#include "basic.hpp"

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
	std::cout << "Reduced form: ";
	p.print();
	std::cout << "Poylnomial degree: " << p.getDegree() << std::endl;
	if (p.getDegree() > 2)
	{
		std::cerr << "The polynomial degree is stricly greater than 2, I can't solve." << std::endl;
		return (1);
	}
	if (p.getDegree() < 2)
		basicSolve(p);
	else
	{
		SecondDegreeEquation e = SecondDegreeEquation(p.getFactor(2), p.getFactor(1), p.getFactor(0));
		std::cout << "Discriminant: " << e.getDelta();
		if (e.getDelta() == 0)
			std::cout << " (There is one real solution)" << std::endl;
		else if (e.getDelta() > 0)
			std::cout << " (There are two real solutions)" << std::endl;
		else
			std::cout << " (There are two complex solutions)" << std::endl;
		e.solve();
	}
	return (0);
}