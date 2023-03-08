/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SecondDegreeEquation.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:43:45 by dhubleur          #+#    #+#             */
/*   Updated: 2023/02/20 16:13:11 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SecondDegreeEquation_HPP
#define SecondDegreeEquation_HPP

# include <iostream>
# include "math.hpp"

class SecondDegreeEquation
{
public:
	SecondDegreeEquation(double a, double b, double c);
	SecondDegreeEquation(SecondDegreeEquation const &src);
	~SecondDegreeEquation();

	SecondDegreeEquation &operator=(SecondDegreeEquation const &rhs);

	double getDelta() const;

	void solve() const;

private:
	SecondDegreeEquation();
	double _a;
	double _b;
	double _c;
	double _delta;
};

#endif