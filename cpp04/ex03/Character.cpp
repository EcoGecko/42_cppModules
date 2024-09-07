/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:24:42 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/19 17:24:43 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : _name(""), _inventoryIndex(0) {

	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
		this->_lostItems[i] = NULL;
	}
}

Character::Character(std::string const &name) : _name(name), _inventoryIndex(0) {

	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
		this->_lostItems[i] = NULL;
	}
}

Character::Character(Character const &obj) {

	*this = obj;
}

Character &Character::operator=(Character const &obj) {

	if (this == &obj) {
		return (*this);
	}
	this->_name = obj._name;
	this->_inventoryIndex = obj._inventoryIndex;
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i]) {
			delete this->_inventory[i];
		}
		this->_inventory[i] = obj._inventory[i]->clone();
		if (this->_inventory[i]) {
			delete this->_lostItems[i];
		}
		this->_lostItems[i] = obj._lostItems[i]->clone();
	}
		return (*this);
}

Character::~Character(void) {

	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i]) {
			delete this->_inventory[i];
			delete this->_lostItems[i];
		}
	}
}

std::string const &Character::getName(void) const {

	return (this->_name);
}
void Character::equip(AMateria *m) {

	if (this->_inventoryIndex > 3 || !m) {
		return ;
	}
	this->_inventory[this->_inventoryIndex] = m;
	this->_inventoryIndex++;
}
void Character::unequip(int idx) {

	if (idx < 0 || idx > 3 || !this->_inventory[idx]) {
		return ;
	}
	this->_lostItems[idx] = this->_inventory[idx];
	this->_inventory[idx] = NULL;

}
void Character::use(int idx, ICharacter &target) {

	this->_inventory[idx]->use(target);
}
