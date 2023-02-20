/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:12:30 by dhubleur          #+#    #+#             */
/*   Updated: 2023/02/20 17:14:39 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.hpp"

double squareRoot(double n)
{
	    double x = n;
        double y = 1;
        double e = 0.000001; /* e decides the accuracy level*/
        while (x - y > e) {
            x = (x + y) / 2;
            y = n / x;
        }
        return x;
}