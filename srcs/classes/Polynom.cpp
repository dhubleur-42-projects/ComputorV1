/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polynom.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:44:05 by dhubleur          #+#    #+#             */
/*   Updated: 2023/02/21 13:28:38 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polynom.hpp"
#include <iostream>
#include <algorithm>

Polynom::Polynom() : _valid(true), _degree(-1) {}

int Polynom::_extractValue(std::string factor, std::pair<double, double> &values)
{
	size_t x = factor.find("X^");
	std::string nbr = factor;
	int valueType = x == std::string::npos ? 0 : 1;
	if (x == std::string::npos)
	{
		x = factor.find("X");
		if (x != std::string::npos)
		{
			valueType = 1;
			nbr = "1";
		}
	}
	else
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
		return -1;
	}
	else
	{
		double value = std::stod(nbr);
		if (valueType == 0)
			values.first = value;
		else
		{
			if (factor[0] == '-')
				values.first = -1;
			values.second = value;
		}
		return valueType;
	}
}

std::pair<double, double> Polynom::_extractValues(std::string &factor)
{
	std::pair<double, double> values(1, 0);
	size_t x = factor.find("X");
	if (x != std::string::npos && x != factor.size() - 1 && factor[x + 1] != '^')
	{
		std::cerr << "Invalid equation (invalid factor '" << factor << "')" << std::endl;
		_valid = false;
	}else {
		if (x != std::string::npos && x != 0 && factor[x - 1] != '*')
		{
			factor = factor.substr(0, x) + "*" + factor.substr(x, factor.size() - x);
		}
		size_t mult = factor.find("*");
		if (mult == std::string::npos)
		{
			_extractValue(factor, values);
		}
		else
		{
			int part1 = _extractValue(factor.substr(0, mult), values);
			int part2 = _extractValue(factor.substr(mult + 1, factor.size() - mult - 1), values);
			if (part1 == part2)
			{
				std::cerr << "Invalid equation (invalid factor '" << factor << "')" << std::endl;
				_valid = false;
			}
		}
	}
	return (values);
}

std::pair<double, double> Polynom::_extractFactor(std::string &factorsList)
{
	std::string factor;
	size_t plus = factorsList.find("+", 1);
	size_t minus = factorsList.find("-", 1);
	size_t x = factorsList.find("X^");
	if (x == std::string::npos)
		x = factorsList.find("X");
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
		if (!_valid)
			return;
	}
	while (right.size() > 0)
	{
		std::pair<double, double> factor = _extractFactor(right);
		factor.first *= -1;
		_factors.push_back(factor);
		_testDegree();
		if (!_valid)
			return;
	}
	this->reduce();
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
		if (i == 0 && factor.first < 0)
			std::cout << "- ";
		if (i > 0)
			std::cout << (factor.first >= 0 ? " + " : " - ");
		if ((factor.first != 1 && factor.first != -1) || factor.second == 0)
			std::cout << (factor.first < 0 ? -factor.first : factor.first);
		if (factor.second > 0)
		{
			if ((factor.first != 1 && factor.first != -1) || factor.second == 0)
				std::cout << " * ";
			std::cout << "X";
		}
		if (factor.second > 1)
			std::cout << "^" << factor.second;
		i++;
	}
	if (i == 0)
		std::cout << "0";
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
	auto new_end = std::remove_if(reduced.begin(), reduced.end(), [](std::pair<double, double> factor)
								  { return (factor.first == 0); });
	reduced.erase(new_end, reduced.end());
	_factors = reduced;
	_degree = _factors.back().second;
}

int Polynom::getDegree() const { return _degree; }

double Polynom::getFactor(int degree) const {
	auto search = std::find_if(_factors.begin(), _factors.end(), [degree](std::pair<double, double> test)
							   { return (test.second == degree); });
	if (search == _factors.end())
		return (0);
	return (search->first);
}