/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polynom.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:43:45 by dhubleur          #+#    #+#             */
/*   Updated: 2023/01/05 14:54:52 by dhubleur         ###   ########.fr       */
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

private:
	std::vector<std::pair<double, double>> _factors;
};

#endif