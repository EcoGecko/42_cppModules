/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:24:50 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/19 17:24:51 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {

}

Cure::Cure(Cure const &obj) : AMateria(obj) {

	*this = obj;
}

Cure &Cure::operator=(Cure const &obj) {

	if (this == &obj) {
		return (*this);
	}
	return (*this);
}

Cure::~Cure(void) {

}

AMateria* Cure::clone(void) const {

	return (new Cure());
}

void Cure::use(ICharacter &target) {

	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
