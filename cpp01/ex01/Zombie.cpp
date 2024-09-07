/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:45:30 by heda-sil          #+#    #+#             */
/*   Updated: 2023/08/24 13:50:02 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) {
}

Zombie::~Zombie(void) {

	std::cout << this->_name << " is dead!" << std::endl;
}

void Zombie::announce(void) const {

	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::getName(void) const {

	return (this->_name);
}

void Zombie::setName(std::string name) {

	this->_name = name;
}
