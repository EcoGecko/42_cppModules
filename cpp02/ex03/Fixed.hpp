/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:15:11 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/16 12:21:08 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

private:
	int				 _fixedValue;
	static int const _fracBits = 8;

public:
	Fixed(void);
	Fixed(Fixed const &obj); // Copy constructor
	Fixed(int const value);
	Fixed(float const value);
	~Fixed();

	/* Assignment operator */
	Fixed	&operator=(Fixed const &obj);

	/* Comparison operators */
	bool	operator>(Fixed const &obj) const;
	bool	operator<(Fixed const &obj) const;
	bool	operator>=(Fixed const &obj) const;
	bool	operator<=(Fixed const &obj) const;
	bool	operator==(Fixed const &obj) const;
	bool	operator!=(Fixed const &obj) const;

	/* Arithmetic operators */
	Fixed	operator+(Fixed const &obj);
	Fixed	operator-(Fixed const &obj);
	Fixed	operator*(Fixed const &obj);
	Fixed	operator/(Fixed const &obj);

	/* Increments/Decrements */
	Fixed	&operator++();
	Fixed	operator++(int);
	Fixed	&operator--();
	Fixed	operator--(int);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const; // Converts Fixed_point to float
	int		toInt(void) const;   // Converts Fixed-point to int
	static	Fixed &min(Fixed &a, Fixed &b);
	static	Fixed const &min(Fixed const &a, Fixed const &b);
	static	Fixed &max(Fixed &a, Fixed &b);
	static	Fixed const &max(Fixed const &a, Fixed const &b);
};

std::ostream	&operator<<(std::ostream &os, Fixed const &obj);
#endif
