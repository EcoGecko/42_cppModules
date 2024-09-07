/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:08:19 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/16 14:23:14 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {

	Point a(0, 0);
	Point b(0, 5);
	Point c(5, 0);
	float x = 1;
	float y = 1;

	if (bsp(a, b, c, Point(x, y))) {
			std::cout << "The point (" << x << ", " << y << ") is inside the triangle" << std::endl;
	} else {
		std::cout << "The point (" << x << ", " << y << ") is outside the triangle" << std::endl;
	}
	x = 3;
	y = 7;
	if (bsp(a, b, c, Point(x, y))) {
			std::cout << "The point (" << x << ", " << y << ") is inside the triangle" << std::endl;
	} else {
		std::cout << "The point (" << x << ", " << y << ") is outside the triangle" << std::endl;
	}
	x = 5.5;
	y = 5.5;
	if (bsp(a, b, c, Point(x, y))) {
			std::cout << "The point (" << x << ", " << y << ") is inside the triangle" << std::endl;
	} else {
		std::cout << "The point (" << x << ", " << y << ") is outside the triangle" << std::endl;
	}
	x = 0.5;
	y = 5.1;
	if (bsp(a, b, c, Point(x, y))) {
			std::cout << "The point (" << x << ", " << y << ") is inside the triangle" << std::endl;
	} else {
		std::cout << "The point (" << x << ", " << y << ") is outside the triangle" << std::endl;
	}
	x = 0;
	y = 0;
	if (bsp(a, b, c, Point(x, y))) {
			std::cout << "The point (" << x << ", " << y << ") is inside the triangle" << std::endl;
	} else {
		std::cout << "The point (" << x << ", " << y << ") is outside the triangle" << std::endl;
	}
	return (0);
}
