/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:19:48 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/30 12:50:02 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("<Default ClapTrap>"), _health(10), _energy(10), _attack(0) {

	std::cout << "ClapTrap " << this->_name << " was created using the default constructor!" << std::endl;
}

ClapTrap::ClapTrap(std::string const &name) : _name(name), _health(10), _energy(10), _attack(0) {

	std::cout << "ClapTrap " << this->_name << " was created using the parameter constructor!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &obj) {

	*this = obj;
	std::cout << "ClapTrap " << this->_name << " was copied!" << std::endl;
}

ClapTrap::~ClapTrap(void) {

	std::cout << "ClapTrap " << this->_name << " was destroyed!" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &obj) {

	if (this == &obj) {
		return (*this);
	}
		this->_attack = obj._attack;
		this->_energy = obj._energy;
		this->_health = obj._health;
		this->_name = obj._name;
	return (*this);
}

void ClapTrap::attack(const std::string &target) {

	if (this->_energy-- > 0 && this->_health) {
		std::cout << "ClapTrap " << this->_name;
		std::cout << " attacks " << target;
		std::cout << ", causing " << this->_attack;
		std::cout << " points of damage!" << std::endl;
		std::cout << "\tClapTrap " << this->_name << " has " << this->_energy;
		std::cout << " energy left!" << std::endl;
	} else if (!this->_health) {
		std::cout << "ClapTrap " << this->_name;
		std::cout << " is broken, therefore cannot attack!" << std::endl;
	} else {
		std::cout << "ClapTrap " << this->_name;
		std::cout << " depleted all his energy!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {

	if ((int)amount > this->_health) {
		amount = this->_health;
	}
	if (this->_health) {
		this->_health -= amount;
		std::cout << "ClapTrap " << this->_name << " was attacked, losing ";
		std::cout << amount << "hp, his hp is now " << this->_health << "!" << std::endl;
	}
	if (this->_health == 0) {
		std::cout << "\tClapTrap " << this->_name << " is destroyed!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {

	if (this->_energy-- && this->_health) {
		this->_health += amount;
		std::cout << "ClapTrap " << this->_name << " is repairing for " << amount;
		std::cout << ",  his hp is now " << this->_health << "!" << std::endl;
		std::cout << "\tClapTrap " << this->_name << " has " << this->_energy;
		std::cout << " energy left!" << std::endl;
	} else if (!this->_health) {
		std::cout << "ClapTrap " << this->_name;
		std::cout << " is destroyed, therefore cannot repair!" << std::endl;
	} else {
		std::cout << "ClapTrap " << this->_name;
		std::cout << " depleted all his energy!" << std::endl;
	}
}
