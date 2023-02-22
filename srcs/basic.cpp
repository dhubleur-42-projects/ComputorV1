/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:13:58 by dhubleur          #+#    #+#             */
/*   Updated: 2023/02/22 18:00:35 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic.hpp"
#include "color.hpp"

void basicSolve(Polynom &p)
{
	if (p.getDegree() == 0)
	{
		if (p.getFactor(0) == 0)
			std::cout << GREEN << "All " << BOLD << "real numbers" << RESET << GREEN << " are solutions of the equation." << RESET << std::endl;
		else
			std::cout << YELLOW << "There is " << BOLD << "no" << RESET << YELLOW << " solution to the equation." << RESET << std::endl;
	}
	else
	{
		std::cout << PURPLE << "There is " << BOLD << "one" << RESET << PURPLE << " real solution and can be computed with the following formula:" << RESET << std::endl;
		std::cout << YELLOW << "x = -b / a  =>  " << BOLD << "x = " << (p.getFactor(0) > 0 ? "-" : "") << (p.getFactor(0) < 0 ? - p.getFactor(0) : p.getFactor(0)) << " / " << p.getFactor(1) << RESET << std::endl;
		std::string x = getAsIrreductibleIfEntire(-p.getFactor(0), p.getFactor(1));
		std::cout << std::endl << GREEN << "The solution is: " << BOLD << x << RESET << std::endl;
	}
}