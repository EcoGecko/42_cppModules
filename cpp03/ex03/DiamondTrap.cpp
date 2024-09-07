/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:36:52 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/30 13:07:09 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : _name("<Default DiamondTrap>") {

	this->_health = 100;
	this->_attack = 30;
	this->_energy = 50;
	this->ClapTrap::_name = _name + "_clap_name";
	std::cout << "Diamond " << this->_name << " was created using the default constructor!" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &obj) : ClapTrap(obj), ScavTrap(obj), FragTrap(obj) {

	*this = obj;
	std::cout << "DiaomondTrap " << this->_name << " was created using the parameter constructor!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string const &name) : ClapTrap(name), ScavTrap(name), FragTrap(name), _name(name) {

	this->_health = 100;
	this->_attack = 30;
	this->_energy = 50;
	this->ClapTrap::_name = name + "_clap_name";
	std::cout << "DiamondTrap " << this->_name << " was created!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &obj) {

	if (this != &obj) {
		this->_name = obj._name;
		this->_health = obj._health;
		this->_energy = obj._energy;
		this->_attack = obj._attack;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void) {

	std::cout << "DiamondTrap " << this->_name << " was destroyed!" << std::endl;
}

void DiamondTrap::whoAmI() {

	std::cout << "My name is " << this->_name << " and my ClapTrap name is ";
	std::cout << this->ClapTrap::_name << std::endl;
}
