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
#include "color.hpp"

SecondDegreeEquation::SecondDegreeEquation(double a, double b, double c) : _a(a), _b(b), _c(c) {
	std::cout << CYAN << "We gonna use the Vieta's formulas to solve this equation. With this parameters: " << BOLD << "a=" << a << " | b=" << b << " | c=" << c << RESET << std::endl;
	const int bSquare = b * b;
	const int fourAC = 4 * a * c;
	std::cout << PURPLE << "We can compute the discriminant with the following formula:" << RESET << std::endl;
	std::cout << YELLOW << "delta = b^2 - 4ac  =>  " << BOLD << "delta = " << b << "^2 - 4 * " << a << " * " << c << "  =>  delta = " << bSquare << (fourAC < 0 ? " + " : " - ") << (fourAC < 0 ? -fourAC : fourAC) << RESET << std::endl;
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
		std::string x = getAsIrreductibleIfEntire(-_b, 2 * _a);
		std::cout << GREEN << "The solution is: " << BOLD << x << RESET << std::endl;
	}
	else if (_delta > 0)
	{
		//Real solutions
		double root = squareRoot(_delta);
		std::cout << CYAN << "Square root of the discriminant: " << BOLD << root << RESET << std::endl;
		std::cout << PURPLE << "We can compute the two solutions with the following formulas:" << RESET << std::endl;
		std::cout << YELLOW << "x = (-b ± sqrt(delta)) / 2a  =>  " << BOLD << "x = (" << -_b << " ± " << root << ") / 2 * " << _a << RESET << std::endl;
		std::string x1 = getAsIrreductibleIfEntire(-_b + root, 2 * _a);
		std::string x2 = getAsIrreductibleIfEntire(-_b - root, 2 * _a);
		std::cout << GREEN << "The solutions are: '" << BOLD << x1 << RESET << GREEN << "' and '" << BOLD << x2 << RESET << GREEN << "'" << std::endl;
	}
	else
	{
		//Complex solutions
		double root = squareRoot(-_delta);
		std::cout << CYAN << "Square root of the discriminant: " << BOLD << root << " * i" << RESET << std::endl;
		std::cout << PURPLE << "We can compute the two solutions with the following formulas:" << RESET << std::endl;
		std::cout << YELLOW << "x = (-b ± sqrt(delta)) / 2a  =>  " << BOLD << "x = (" << -_b << " ± " << root << " * i) / 2 * " << _a << RESET << std::endl;
		const double doubleA = 2 * _a;
		std::cout << GREEN << "The solutions are: '" << BOLD << getAsIrreductibleIfEntire(-_b, doubleA) << " + " << getAsIrreductibleIfEntire(root, doubleA) << " * i" << RESET << GREEN << "' and '" << BOLD << getAsIrreductibleIfEntire(-_b, doubleA) << " - " << getAsIrreductibleIfEntire(root, doubleA) << " * i" << RESET << GREEN << "'" << std::endl;
	}
}