/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:02:33 by heda-sil          #+#    #+#             */
/*   Updated: 2023/09/22 15:51:34 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() : _firstName(""), _lastName(""), _nickname(""), _phoneNbr(""), _darkSecret("") {
	return;
}

Contact::~Contact() {
	return;
}

void Contact::setValues(std::string new_value, std::string field) {

	if (field == FNAME) {
		this->_firstName = new_value;
	} else if (field == LNAME) {
		this->_lastName = new_value;
	} else if (field == NICK) {
		this->_nickname = new_value;
	} else if (field == PHONE) {
		this->_phoneNbr = new_value;
	} else if (field == SECRET) {
		this->_darkSecret = new_value;
	}
	return;
}

std::string Contact::getValues(std::string field) const {

	if (field == FNAME) {
		return (this->_firstName);
	} else if (field == LNAME) {
		return (this->_lastName);
	} else if (field == NICK) {
		return (this->_nickname);
	} else if (field == PHONE) {
		return (this->_phoneNbr);
	} else if (field == SECRET) {
		return (this->_darkSecret);
	}
	return (NULL);
}
