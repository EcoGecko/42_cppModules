/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:00:06 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/04 11:58:55 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string const name) : _name(name), _weapon(NULL) {
}

HumanB::~HumanB() {

}

void HumanB::attack(void) const {

	if (this->_weapon == NULL) {
		std::cout << this->_name << " has no weapon" << std::endl;
		return ;
	}
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {

	this->_weapon = &weapon;
}
