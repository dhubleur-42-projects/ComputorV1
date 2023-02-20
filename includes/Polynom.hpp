/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polynom.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:43:45 by dhubleur          #+#    #+#             */
/*   Updated: 2023/02/20 17:49:31 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYNOM_HPP
#define POLYNOM_HPP

#include <string>
#include <vector>

class Polynom
{
public:
	Polynom();
	Polynom(std::string equation);
	Polynom(Polynom const &src);
	~Polynom();

	Polynom &operator=(Polynom const &rhs);

	bool isValid() const;
	void print() const;
	void reduce();
	int getDegree() const;
	double getFactor(int degree) const;

private:
	std::vector<std::pair<double, double>>
		_factors;
	bool _valid;
	int _degree;

	std::pair<double, double> _extractFactor(std::string &factorsList);
	std::pair<double, double> _extractValues(std::string &factor);
	int _extractValue(std::string factor, std::pair<double, double> &values);
	void _testDegree();
};

#endif