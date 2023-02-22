/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:41:56 by dhubleur          #+#    #+#             */
/*   Updated: 2023/02/22 18:13:57 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Polynom.hpp"
#include "SecondDegreeEquation.hpp"
#include "basic.hpp"
#include "color.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << RED << "Usage: ./computor <equation>" << RESET << std::endl;
		return (1);
	}
	Polynom p = Polynom(std::string(argv[1]));
	if (!p.isValid())
		return (1);
	std::cout << GREEN << "Reduced form: " << BOLD;
	p.print();
	std::cout << RESET << YELLOW << "Poylnomial degree: " << BOLD << p.getDegree() << RESET << std::endl;
	if (p.getDegree() > 2)
	{
		std::cerr << RED << "The polynomial degree is stricly greater than 2, I can't solve." << RESET << std::endl;
		return (1);
	}
	std::cout << std::endl;
	if (p.getDegree() < 2)
		basicSolve(p);
	else
	{
		SecondDegreeEquation e = SecondDegreeEquation(p.getFactor(2), p.getFactor(1), p.getFactor(0));
		std::cout << GREEN << "Discriminant: " << BOLD << e.getDelta() << RESET << GREEN;
		if (e.getDelta() == 0)
			std::cout << " (There is one real solution)" << RESET << std::endl << std::endl;
		else if (e.getDelta() > 0)
			std::cout << " (There are two real solutions)" << RESET << std::endl << std::endl;
		else
			std::cout << " (There are two complex solutions)" << RESET << std::endl << std::endl;
		e.solve();
	}
	return (0);
}