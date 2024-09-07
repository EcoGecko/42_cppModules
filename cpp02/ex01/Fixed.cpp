/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:33:53 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/16 11:33:50 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedValue(0) {

	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &obj) {

	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::Fixed(int const value) {

	std::cout << "Int constructor called" << std::endl;
	this->_fixedValue = value * (1 << this->_fracBits);
}

Fixed::Fixed(float const value) {

	std::cout << "Float constructor called" << std::endl;
	this->_fixedValue = roundf(value * (1 << this->_fracBits));
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

	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedValue);
}

void Fixed::setRawBits(int const raw) {

	this->_fixedValue = raw;
}

float Fixed::toFloat(void) const {

	return (((float)this->_fixedValue / (1 << this->_fracBits)));
}

int Fixed::toInt(void) const {

	return (this->_fixedValue / (1 << this->_fracBits));
}

std::ostream &operator<<(std::ostream &os, Fixed const &obj) {

	os << obj.toFloat();
	return (os);
}
