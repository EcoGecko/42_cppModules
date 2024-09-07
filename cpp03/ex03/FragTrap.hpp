/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 12:54:31 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/18 08:43:51 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

public:
	FragTrap(void);
	FragTrap(std::string const &name);
	FragTrap(FragTrap const &src);
	~FragTrap(void);

	FragTrap &operator=(FragTrap const &src);

	void	  highFivesGuys(void);

};
#endif
