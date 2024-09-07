/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:36:47 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/18 09:20:08 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include <string>
#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {

private:
	std::string _name;

public:
	DiamondTrap(void);
	DiamondTrap(std::string const &name);
	DiamondTrap(DiamondTrap const &obj);

	DiamondTrap &operator=(DiamondTrap const &obj);

	~DiamondTrap(void);

	void whoAmI();
	using ScavTrap::attack;
};

#endif
