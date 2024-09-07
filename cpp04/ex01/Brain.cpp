/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:52:31 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/30 16:05:59 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {

	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < NBR_IDEAS; i++) {
		this->ideas[i] = "idea";
	}
}

Brain::Brain(Brain const &obj) {

	std::cout << "Brain copy constructor called" << std::endl;
	*this = obj;
}

Brain &Brain::operator=(Brain const &obj) {

	std::cout << "Brain assigment operator called" << std::endl;
	if (this == &obj) {
		return (*this);
	}
	for (int i = 0; i < NBR_IDEAS; i++) {
		this->ideas[i] = obj.ideas[i];
	}
	return *this;
}

Brain::~Brain(void) {

	std::cout << "Brain destructor called" << std::endl;
}
