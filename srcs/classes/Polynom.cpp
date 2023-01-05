/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polynom.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:44:05 by dhubleur          #+#    #+#             */
/*   Updated: 2023/01/05 16:23:22 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polynom.hpp"
#include <iostream>
#include <algorithm>

Polynom::Polynom() : _valid(true), _degree(-1) {}

void Polynom::_extractValue(std::string factor, std::pair<double, double> &values)
{
	size_t x = factor.find("X^");
	std::string nbr = factor;
	int valueType = x == std::string::npos ? 0 : 1;
	if (x != std::string::npos)
		nbr = factor.substr(x + 2, factor.size() - x - 2);
	size_t pos = 0;
	if (nbr[0] == '-' || nbr[0] == '+')
		pos++;
	bool point = false;
	bool isNumber = std::ranges::all_of(nbr.begin() + pos, nbr.end(), [point](char c) mutable
										{
											if (c == '.')
											{
												if (point)
													return (false);
												point = true;
												return (true);
											}
											return (std::isdigit(c) ? true : false); });
	if (!isNumber)
	{
		std::cerr << "Invalid equation ('" << nbr << "' is not a number)" << std::endl;
		_valid = false;
	}
	else
	{
		double value = std::stod(nbr);
		if (valueType == 0)
			values.first = value;
		else
			values.second = value;
	}
}

std::pair<double, double> Polynom::_extractValues(std::string &factor)
{
	std::pair<double, double> values(1, 0);
	size_t mult = factor.find("*");
	if (mult == std::string::npos)
	{
		_extractValue(factor, values);
	}
	else
	{
		_extractValue(factor.substr(0, mult), values);
		_extractValue(factor.substr(mult + 1, factor.size() - mult - 1), values);
	}
	return (values);
}

std::pair<double, double> Polynom::_extractFactor(std::string &factorsList)
{
	std::string factor;
	size_t plus = factorsList.find("+", 1);
	size_t minus = factorsList.find("-", 1);
	size_t x = factorsList.find("X^");
	if (x != std::string::npos && (plus == x + 2))
		plus = std::string::npos;
	else if (x != std::string::npos && (minus == x + 2))
		minus = std::string::npos;
	if (plus == std::string::npos && minus == std::string::npos)
	{
		factor = factorsList;
		factorsList = "";
	}
	else
	{
		if (plus == std::string::npos || minus < plus)
		{
			factor = factorsList.substr(0, minus);
			factorsList = factorsList.substr(minus, factorsList.size() - minus);
		}
		else
		{
			factor = factorsList.substr(0, plus);
			factorsList = factorsList.substr(plus, factorsList.size() - plus);
		}
	}
	return (_extractValues(factor));
}

void Polynom::_testDegree()
{
	if (_factors.back().second < 0)
	{
		_valid = false;
		std::cerr << "Invalid equation (degree must be greater or equals than 0)" << std::endl;
	}
	if ((int)_factors.back().second != _factors.back().second)
	{
		_valid = false;
		std::cerr << "Invalid equation (degree must be an integer)" << std::endl;
	}
	if (_factors.back().second > _degree)
		_degree = _factors.back().second;
}

Polynom::Polynom(std::string equation) : _valid(true), _degree(-1)
{
	equation.erase(std::remove(equation.begin(), equation.end(), ' '), equation.end());
	size_t equal = equation.find("=");
	if (equal == std::string::npos)
	{
		_valid = false;
		std::cerr << "Invalid equation (need a '=')" << std::endl;
		return;
	}
	std::string left = equation.substr(0, equal);
	std::string right = equation.substr(equal + 1, equation.size() - equal - 1);
	while (left.size() > 0)
	{
		std::pair<double, double> factor = _extractFactor(left);
		_factors.push_back(factor);
		_testDegree();
	}
	while (right.size() > 0)
	{
		std::pair<double, double> factor = _extractFactor(right);
		factor.first *= -1;
		_factors.push_back(factor);
		_testDegree();
	}
}

Polynom::Polynom(Polynom const &src) { *this = src; }

Polynom::~Polynom() {}

Polynom &Polynom::operator=(Polynom const &rhs)
{
	_factors = rhs._factors;
	_valid = rhs._valid;
	_degree = rhs._degree;
	return (*this);
}

bool Polynom::isValid() const { return (_valid); }

void Polynom::print() const
{
	int i = 0;
	for (std::pair<double, double> factor : _factors)
	{
		if (i > 0)
		{
			std::cout << (factor.first >= 0 ? " + " : " - ");
		}
		std::cout << (factor.first < 0 ? -factor.first : factor.first) << " * X^" << factor.second;
		i++;
	}
	std::cout << " = 0" << std::endl;
}

void Polynom::reduce()
{
	std::sort(_factors.begin(), _factors.end(), [](std::pair<double, double> a, std::pair<double, double> b)
			  { return (a.second < b.second); });
	std::vector<std::pair<double, double>> reduced;
	for (std::pair<double, double> factor : _factors)
	{
		auto search = std::find_if(reduced.begin(), reduced.end(), [factor](std::pair<double, double> test)
								   { return (test.second == factor.second); });
		if (search == reduced.end())
		{
			reduced.push_back(factor);
		}
		else
		{
			search->first += factor.first;
		}
	}
	_factors = reduced;
}

int Polynom::getDegree() const { return _degree; }