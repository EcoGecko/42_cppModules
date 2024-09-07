/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:45:33 by heda-sil          #+#    #+#             */
/*   Updated: 2023/08/24 13:43:22 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {

public:
	Zombie(void);
	~Zombie(void);

	void		announce(void) const;
	std::string getName(void) const;
	void		setName(std::string name);

private:
	std::string _name;
};

#endif
