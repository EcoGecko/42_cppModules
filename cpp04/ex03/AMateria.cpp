/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:24:37 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/19 17:24:38 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : _type("<Default materia>") {
}

AMateria::AMateria(std::string const &type) : _type(type) {

}

AMateria::AMateria(AMateria const &obj) {

	*this = obj;
}

AMateria &AMateria::operator=(AMateria const &obj) {

	if (this == &obj) {
		return (*this);
	}
	return (*this);
}

AMateria::~AMateria(void) {
}

std::string const &AMateria::getType(void) const {

	return (this->_type);
}

void AMateria::use(ICharacter& target) {

	(void)target;
}
