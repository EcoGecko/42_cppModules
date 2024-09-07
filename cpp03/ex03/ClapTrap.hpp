/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:19:40 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/30 14:29:46 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {

protected:
	std::string	_name;
	int			_health;
	int			_energy;
	int			_attack;

public:
	ClapTrap(void);
	ClapTrap(std::string const &name);
	ClapTrap(ClapTrap const &obj);

	ClapTrap &operator=(ClapTrap const &obj);

	~ClapTrap(void);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif
