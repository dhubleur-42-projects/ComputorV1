/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:12:30 by dhubleur          #+#    #+#             */
/*   Updated: 2023/03/08 18:20:40 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <iomanip>
#include "math.hpp"

double squareRoot(double n)
{
	    double x = n;
        double y = 1;
        double e = 0.0000001;
        while (x - y > e) {
            x = (x + y) / 2;
            y = n / x;
        }
		std::stringstream res;
		res << std::setprecision(6) << x;
		return (std::stod(res.str()));
}

bool isInteger(double n)
{
	return (n == (int)n);
}

std::string asString(double n)
{
	std::stringstream ss;
	ss << n;
	return (ss.str());
}

std::string getAsIrreductibleIfEntire(double n, double divider)
{
	if (n == 0)
		return ("0");
	else if (divider == 0)
		return ("inf");
	else if (!isInteger(n) || !isInteger(divider))
	{
		const double res = n / divider;
		return (asString(res));
	}
	else if (isInteger(n/divider))
		return (asString(n / divider));
	else
	{
		if (n < 0 && divider < 0)
		{
			n = -n;
			divider = -divider;
		}
		int factor = 2;
		while (factor <= n || factor <= divider) {
			while (isInteger(n / factor) && isInteger(divider / factor))
			{
				n /= factor;
				divider /= factor;
			}
			factor++;
		}
		return (asString(n) + "/" + asString(divider));
	}
}