/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:26:28 by heda-sil          #+#    #+#             */
/*   Updated: 2023/09/23 12:47:11 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {

private:
	std::string _type;

public:
	Weapon(std::string type);
	~Weapon();

	std::string const &getType() const;
	void			   setType(std::string const type);
};

#endif
