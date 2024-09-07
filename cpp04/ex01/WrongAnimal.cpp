/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:16:19 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/30 16:12:01 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {

	std::cout << "WrongAnimal default constructor called" << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(WrongAnimal const &obj) {

	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this  = obj;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &obj) {

	std::cout << "WrongAnimal assigment operator called" << std::endl;
	if (this == &obj) {
		return (*this);
	}
	this->type = obj.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void) {

	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType(void) const {

	return (this->type);
}

void WrongAnimal::makeSound(void) const {

	std::cout << "Wrong Animal: Wait, what sound am I suppose to make?" << std::endl;
}
