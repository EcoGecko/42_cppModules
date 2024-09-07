/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:23:52 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/30 16:12:05 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) {

	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";

}

WrongCat::WrongCat(WrongCat const &obj) : WrongAnimal(obj) {

	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = obj;
}

WrongCat &WrongCat::operator=(WrongCat const &obj) {

	std::cout << "WrongCat assigment operator called" << std::endl;
	if (this == &obj) {
		return (*this);
	}
	this->type = obj.type;
	return (*this);
}

WrongCat::~WrongCat(void) {

	std::cout << "WrongCat destructor called" << std::endl;
}
