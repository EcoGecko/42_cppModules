/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:16:11 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/30 16:11:17 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("Animal") {

	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal const &obj) {

	std::cout << "Animal copy constructor called" << std::endl;
	*this  = obj;
}

Animal &Animal::operator=(Animal const &obj) {

	std::cout << "Animal assigment operator called" << std::endl;
	if (this == &obj) {
		return (*this);
	}
	this->type = obj.type;
	return (*this);
}

Animal::~Animal(void) {

	std::cout << "Animal destructor called" << std::endl;
}

std::string	Animal::getType(void) const {

	return (this->type);
}

void Animal::makeSound(void) const {

	std::cout << "Animal: Wait, what sound am I suppose to make?" << std::endl;
}
