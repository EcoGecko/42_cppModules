/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:33:53 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/16 11:19:16 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _fixedValue(0) {

	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &obj) {

	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::~Fixed() {

	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &obj) {

	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj) {
		this->_fixedValue = obj.getRawBits();
	}
	return (*this);
}

int Fixed::getRawBits(void) const {

	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedValue);
}

void Fixed::setRawBits(int const raw) {

	this->_fixedValue = raw;
}
