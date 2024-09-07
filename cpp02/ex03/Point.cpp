/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:35:45 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/16 14:20:51 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

Point::Point() : _x(0), _y(0) {
}

Point::Point(float const x, float const y) : _x(x), _y(y) {
}

Point::Point(Point const &obj) : _x(obj._x), _y(obj._y) {

}

Point::~Point() {
}

Point &Point::operator=(Point const &obj) {

	(void)obj;
	return (*this);
}

Fixed Point::getX(void) const {
	return (Fixed(this->_x));
}

Fixed Point::getY(void) const {
	return (Fixed(this->_y));
}
