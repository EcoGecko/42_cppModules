/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:04:18 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/18 08:45:03 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

public:
	ScavTrap(void);
	ScavTrap(std::string const &name);
	ScavTrap(ScavTrap const &obj);

	ScavTrap &operator=(ScavTrap const &obj);

	~ScavTrap(void);

	void guardGate();
	void attack(const std::string &target);

};

#endif
