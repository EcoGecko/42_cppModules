/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:15:11 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/16 11:28:43 by heda-sil         ###   ########.fr       */
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

	Fixed &operator=(Fixed const &obj);

	int	  getRawBits(void) const;
	void  setRawBits(int const raw);
	float toFloat(void) const; // Converts Fixed_point to float
	int	  toInt(void) const;   // Converts Fixed-point to int
};

std::ostream &operator<<(std::ostream &os, Fixed const &obj);
#endif
