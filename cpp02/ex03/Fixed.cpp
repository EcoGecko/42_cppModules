/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:33:53 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/16 13:26:24 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedValue(0) {

}

Fixed::Fixed(Fixed const &src) {

	*this = src;
}

Fixed::Fixed(int const value) {

	this->_fixedValue = value << this->_fracBits;
}

Fixed::Fixed(float const value) {

	this->_fixedValue = roundf(value * (1 << this->_fracBits));
}

Fixed::~Fixed() {

}

Fixed &Fixed::operator=(Fixed const &obj) {

	if (this != &obj) {
		this->_fixedValue = obj.getRawBits();
	}
	return (*this);
}

bool Fixed::operator>(Fixed const &obj) const {

	return (obj < *this);
}

bool Fixed::operator<(Fixed const &obj) const {

	return (this->getRawBits() < obj.getRawBits());
}

bool Fixed::operator>=(Fixed const &obj) const {

	return (!(*this < obj));
}

bool Fixed::operator<=(Fixed const &obj) const {

	return (!(*this > obj));
}

bool Fixed::operator==(Fixed const &obj) const {

	return (this->getRawBits() == obj.getRawBits());
}

bool Fixed::operator!=(Fixed const &obj) const {

	return (!(*this == obj));
}

/* Arithmetic operators */
Fixed Fixed::operator+(Fixed const &obj) {

	return (this->toFloat() + obj.toFloat());
}

Fixed Fixed::operator-(Fixed const &obj) {

	return (this->toFloat() - obj.toFloat());
}

Fixed Fixed::operator*(Fixed const &obj) {

	return (this->toFloat() * obj.toFloat());
}

Fixed Fixed::operator/(Fixed const &obj) {

	return (this->toFloat() / obj.toFloat());
}

/* Increments/Decrements */
Fixed &Fixed::operator++() {

	this->_fixedValue++;
	return (*this);
}

Fixed Fixed::operator++(int) {

	Fixed old(*this);

	operator++();
	return (old);
}

Fixed &Fixed::operator--() {

	this->_fixedValue--;
	return (*this);
}

Fixed Fixed::operator--(int) {

	Fixed old(*this);

	operator--();
	return (old);
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

Fixed &Fixed::min(Fixed &a, Fixed &b) {

	return (a < b ? a : b);
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b) {

	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {

	return (a > b ? a : b);
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b) {

	return (a > b ? a : b);
}
