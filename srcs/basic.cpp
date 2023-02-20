/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:13:58 by dhubleur          #+#    #+#             */
/*   Updated: 2023/02/20 16:22:14 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basic.hpp"

void basicSolve(Polynom &p)
{
	if (p.getDegree() == 0)
	{
		if (p.getFactor(0) == 0)
			std::cout << "All real numbers are solutions of the equation." << std::endl;
		else
			std::cout << "There is no solution to the equation." << std::endl;
	}
	else
	{
		double x = (double)-p.getFactor(0) / p.getFactor(1);
		std::cout << "The solution is: " << x << std::endl;
	}
}