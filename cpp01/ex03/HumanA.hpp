/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:54:11 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/04 11:53:15 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA {

private:
	std::string name;
	Weapon	   	&weapon;

public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA(void);

	void attack(void) const;
};

#endif
