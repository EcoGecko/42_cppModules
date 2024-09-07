/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:08:19 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/06 16:18:11 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void) {

	Fixed		a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;

	Fixed e(12);
	Fixed f(12);

	std::cout << "e = " << e << std::endl;
	std::cout << "f = " << f << std::endl;

	if (e < f) {
		std::cout << "e < f" << std::endl;
	}
	if (e > f) {
		std::cout << "e > f" << std::endl;
	}
	if (e >= f) {
		std::cout << "e >= f" << std::endl;
	}
	if (e <= f) {
		std::cout << "e <= f" << std::endl;
	}
	if (e == f) {
		std::cout << "e == f" << std::endl;
	}
	if (e != f) {
		std::cout << "e != f" << std::endl;
	}

	std::cout << "e + f = " << e + f << std::endl;
	std::cout << "e - f = " << e - f << std::endl;
	std::cout << "e / f = " << e / f << std::endl;
	std::cout << "e * f = " << e * f << std::endl;

	return (0);
}
