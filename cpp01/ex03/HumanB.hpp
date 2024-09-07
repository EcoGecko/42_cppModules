/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:57:36 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/04 11:57:23 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB {

private:
	std::string _name;
	Weapon	   	*_weapon;

public:
	HumanB(std::string const name);
	~HumanB(void);

	void attack(void) const;
	void setWeapon(Weapon &weapon);
};

#endif
