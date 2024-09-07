/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:24:45 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/19 17:24:46 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_H
#define CHARACTER_H

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

class Character : public ICharacter {

private:
	std::string _name;
	AMateria	 *_inventory[4];
	AMateria	 *_lostItems[4];
	size_t		_inventoryIndex;

public:
	Character(void);
	Character(Character const &obj);
	Character(std::string const &name);

	Character &operator=(Character const &obj);

	~Character(void);

	std::string const &getName(void) const;
	void			   equip(AMateria *m);
	void			   unequip(int idx);
	void			   use(int idx, ICharacter &target);
};

#endif
