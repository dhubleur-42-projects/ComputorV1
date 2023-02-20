/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SecondDegreeEquation.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:07:26 by dhubleur          #+#    #+#             */
/*   Updated: 2023/02/20 16:13:29 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SecondDegreeEquation.hpp"

SecondDegreeEquation::SecondDegreeEquation(int a, int b, int c) : _a(a), _b(b), _c(c) {
	const int bSquare = b * b;
	const int fourAC = 4 * a * c;
	std::cout << "We can compute the discriminant with the following formula:" << std::endl;
	std::cout << "delta = b^2 - 4ac  =>  delta = " << b << "^2 - 4 * " << a << " * " << c << "  =>  " << bSquare << (fourAC > 0 ? " - " : " + ") << (fourAC < 0 ? -fourAC : fourAC) << std::endl;
	_delta = bSquare - fourAC;
}

SecondDegreeEquation::SecondDegreeEquation(SecondDegreeEquation const &src) : _a(src._a), _b(src._b), _c(src._c), _delta(src._delta) {}

SecondDegreeEquation::~SecondDegreeEquation() {}

SecondDegreeEquation & SecondDegreeEquation::operator=(SecondDegreeEquation const &rhs)
{
	_a = rhs._a;
	_b = rhs._b;
	_c = rhs._c;
	_delta = rhs._delta;
	return *this;
}

double SecondDegreeEquation::getDelta() const
{
	return _delta;
}

void SecondDegreeEquation::solve() const 
{
	if (_delta == 0)
	{
		double x = (double)-_b / (2 * _a);
		std::cout << "The solution is: " << x << std::endl;
	}
	else if (_delta > 0)
	{
		std::cout << "The solutions are real" << std::endl;
	}
	else
	{
		std::cout << "The solution are complex." << std::endl;
	}
}