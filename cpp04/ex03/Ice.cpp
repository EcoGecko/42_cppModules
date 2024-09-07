/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:24:33 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/19 17:24:34 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {

}

Ice::Ice(Ice const &obj) : AMateria(obj) {

	*this = obj;
}

Ice &Ice::operator=(Ice const &obj) {

	if (this == &obj) {
		return (*this);
	}
	return (*this);
}

Ice::~Ice(void) {

}

AMateria* Ice::clone(void) const {

	return (new Ice());
}

void Ice::use(ICharacter &target) {

	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
