/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polynom.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:44:05 by dhubleur          #+#    #+#             */
/*   Updated: 2023/01/05 14:56:06 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Polynom.hpp"
#include <iostream>

Polynom::Polynom() {}
Polynom::Polynom(std::string equation)
{
	std::cerr << "Polynom constructor called with equation: " << equation << std::endl;
}
Polynom::Polynom(Polynom const &src) { *this = src; }
Polynom::~Polynom() {}
Polynom &Polynom::operator=(Polynom const &rhs)
{
	_factors = rhs._factors;
	return (*this);
}