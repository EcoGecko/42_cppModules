/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:17:47 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/30 16:11:53 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) {

	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(Cat const &obj) : Animal(obj) {

	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = NULL;
	*this = obj;
}

Cat &Cat::operator=(Cat const &obj) {

	std::cout << "Cat assigment operator called" << std::endl;
	if (this == &obj) {
		return (*this);
	}
	delete this->brain;
	this->brain = new Brain(*obj.brain);
	this->type = obj.type;
	return (*this);
}

Cat::~Cat(void) {

	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

void Cat::makeSound(void) const {

	std::cout << "Cat: Meooww" << std::endl;
}

Brain *Cat::getBrain(void) const {

	return (this->brain);
}
