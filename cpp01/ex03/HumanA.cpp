/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:52:24 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/04 11:53:35 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {
}

HumanA::~HumanA() {
}

void HumanA::attack(void) const {

	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
