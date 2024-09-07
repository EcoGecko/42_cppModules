/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:56:20 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/30 12:52:34 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {

	this->_name = "<Default FragTrap";
	this->_health = 100;
	this->_energy = 100;
	this->_attack = 30;
	std::cout << "FragTrap " << this->_name << " was created using the default constructor!" << std::endl;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name) {

	this->_health = 100;
	this->_energy = 100;
	this->_attack = 30;
	std::cout << "FragTrap " << this->_name << " was created using the parameter constructor!" << std::endl;
}

FragTrap::FragTrap(FragTrap const &obj) : ClapTrap(obj) {

	*this = obj;
	std::cout << "FragTrap " << this->_name << " was copied!" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &obj) {

	if (this != &obj) {
		this->_name = obj._name;
		this->_health = obj._health;
		this->_energy = obj._energy;
		this->_attack = obj._attack;
	}
	return (*this);
}

FragTrap::~FragTrap() {

	std::cout << "FragTrap " << this->_name << " was destroyed!" << std::endl;
}

void FragTrap::highFivesGuys(void) {

	std::cout << "FragTrap " << this->_name << " requests a high five!" << std::endl;
}
