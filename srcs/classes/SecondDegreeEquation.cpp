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

SecondDegreeEquation::SecondDegreeEquation(int a, int b, int c) : _a(a), _b(b), _c(c) {}

SecondDegreeEquation::SecondDegreeEquation(SecondDegreeEquation const &src) : _a(src._a), _b(src._b), _c(src._c) {}

SecondDegreeEquation::~SecondDegreeEquation() {}

SecondDegreeEquation & SecondDegreeEquation::operator=(SecondDegreeEquation const &rhs)
{
	_a = rhs._a;
	_b = rhs._b;
	_c = rhs._c;
	return *this;
}