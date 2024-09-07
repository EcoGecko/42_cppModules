/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:35:48 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/16 14:21:08 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {

private:
	Fixed const _x;
	Fixed const _y;

public:
	Point(void);
	Point(float const x, float const y);
	Point(Point const &obj);
	~Point();

	Point &operator=(Point const &obj);

	Fixed getX(void) const;
	Fixed getY(void) const;
};

#endif
