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

class SecondDegreeEquation
{
public:
	SecondDegreeEquation(int a, int b, int c);
	SecondDegreeEquation(SecondDegreeEquation const &src);
	~SecondDegreeEquation();

	SecondDegreeEquation &operator=(SecondDegreeEquation const &rhs);

	double getDelta() const;

	void solve() const;

private:
	SecondDegreeEquation();
	int _a;
	int _b;
	int _c;
	double _delta;
};

#endif