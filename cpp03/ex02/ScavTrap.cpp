/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:11:30 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/30 12:50:59 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {

	this->_name = "<Default ScavTrap>";
	this->_health = 100;
	this->_energy = 50;
	this->_attack = 20;
	std::cout << "ScavTrap " << this->_name << " was created using the default constructor!" << std::endl;
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name) {

	this->_health = 100;
	this->_energy = 50;
	this->_attack = 20;
	std::cout << "ScavTrap " << this->_name << " was created using the parameter constructor!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &obj) : ClapTrap(obj) {

	*this = obj;
	std::cout << "ScavTrap " << this->_name << " was copied!" << std::endl;
}

ScavTrap::~ScavTrap(void) {

	std::cout << "ScavTrap " << this->_name << " was destroyed!" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &obj) {

	if (this == &obj) {
		return (*this);
	}
		this->_name = obj._name;
		this->_health = obj._health;
		this->_energy = obj._energy;
		this->_attack = obj._attack;
	return (*this);
}

void ScavTrap::guardGate() {

	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode!" << std::endl;
}

void ScavTrap::attack(const std::string &target) {

	if (this->_energy-- > 0 && this->_health) {
		std::cout << "ScavTrap " << this->_name;
		std::cout << " attacks " << target;
		std::cout << ", causing " << this->_attack;
		std::cout << " points of damage!" << std::endl;
		std::cout << "\tScavTrap " << this->_name << " has " << this->_energy;
		std::cout << " energy left!" << std::endl;
	} else if (!this->_health) {
		std::cout << "ScavTrap " << this->_name;
		std::cout << " is destroyed, therefore cannot attack!" << std::endl;
	} else {
		std::cout << "ScavTrap " << this->_name;
		std::cout << " depleted all his energy!" << std::endl;
	}
}
