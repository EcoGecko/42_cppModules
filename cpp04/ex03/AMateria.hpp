/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:24:40 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/19 17:24:41 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
#define AMATERIA_H

#include "ICharacter.hpp"
#include <iostream>
#include <string>

class AMateria {

protected:
	std::string _type;

public:
	AMateria(void);
	AMateria(AMateria const &obj);
	AMateria(std::string const &type);

	AMateria &operator=(AMateria const &obj);

	virtual ~AMateria(void);

	std::string const &getType(void) const;

	virtual AMateria *clone(void) const = 0;
	virtual void	  use(ICharacter &target);
};

#endif
