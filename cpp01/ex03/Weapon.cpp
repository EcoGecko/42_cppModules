/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:26:54 by heda-sil          #+#    #+#             */
/*   Updated: 2023/09/23 12:47:07 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {
}

Weapon::~Weapon() {
}

std::string const &Weapon::getType() const {

	return (this->_type);
}

void Weapon::setType(std::string type) {

	this->_type = type;
}
