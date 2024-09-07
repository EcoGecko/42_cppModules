/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:35:39 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/16 14:22:00 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

float abs(float const value) {
	return (value < 0 ? -value : value);
}

float area(Point const a, Point const b, Point const c) {

	Fixed first(a.getX() * b.getY() - c.getX() * b.getY());
	Fixed second(c.getX() * a.getY() - a.getX() * c.getY());
	Fixed third(b.getX() * c.getY() - b.getX() * a.getY());
	Fixed result(first + second + third);

	return (abs(result.toFloat() / 2));
}

bool	segment(Point const p1, Point const p2, Point const point) {
	// (p2.x - p1.x)(p.y - p1.y) = (p.x - p1.x)(p2.y - p1.y)
	Fixed	baX(p2.getX() - p1.getX());
	Fixed	PointX(point.getX() - p1.getX());
	Fixed	baY(p2.getY() - p1.getY());
	Fixed	PointY(point.getY() - p1.getY());

	return ((baX * PointY) == (baY * PointX));
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	if (segment(a, b, point) || segment(b, c, point) || segment(a, c, point)) {
		return (false);
	}
	if (area(a, b, c) == area(point, b, c) + area(a, point, c) + area(a, b, point)) {
		return (true);
	}
	return (false);
}
