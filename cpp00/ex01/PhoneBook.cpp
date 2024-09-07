/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:01:14 by heda-sil          #+#    #+#             */
/*   Updated: 2023/09/22 15:43:03 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstring>

PhoneBook::PhoneBook() : _nbrElements(0), _idx(-1) {
	return;
}

PhoneBook::~PhoneBook() {
	return;
}

bool PhoneBook::_validString(const std::string &str) const {

	for (std::string::size_type i = 0; i < str.size(); i++) {
		if (!isalpha(str[i])) {
			return (false);
		}
	}
	return (true);
}

bool PhoneBook::_validNumber(const std::string &str) const {

	for (std::string::size_type i = 0; i < str.size(); i++) {
		if (!isdigit(str[i])) {
			return (false);
		}
	}
	return (true);
}

bool PhoneBook::_validNickname(const std::string &str) const {

	for (std::string::size_type i = 0; i < str.size(); i++) {
		if (!isprint(str[i])) {
			return (false);
		}
	}
	return (true);
}

void PhoneBook::addContact(void) {

	std::string buff;

	if (this->_idx < NBR_CONTACTS) {
		this->_idx++;
	}
	if (this->_idx == NBR_CONTACTS) {
		for (int i = 0; i < this->_idx - 1; i++) {
			this->_contact[i] = this->_contact[i + 1];
		}
		this->_idx--;
	} else if (this->_nbrElements != NBR_CONTACTS) {
		this->_nbrElements++;
	}
	this->_addNames(FNAME);
	this->_addNames(LNAME);
	this->_addText(NICK);
	this->_addNbr(PHONE);
	this->_addText(SECRET);
}

void PhoneBook::_addNbr(const std::string field) {

	std::string buff;

	while (true) {
		std::cout << field;
		std::getline(std::cin, buff);
		if (_validNumber(buff) && !buff.empty()) {
			this->_contact[this->_idx].setValues(buff, PHONE);
			break;
		} else if (buff.empty()) {
			std::cout << "Field can not be empty." << std::endl;
		} else {
			std::cout << "Invalid input." << std::endl;
		}
	}
}

void PhoneBook::_addText(const std::string field) {

	std::string buff;

	while (true) {

		std::cout << field;
		std::getline(std::cin, buff);
		if (field == NICK &&_validNickname(buff) && !buff.empty()) {
			this->_contact[this->_idx].setValues(buff, NICK);
			break;
		} else if (field == SECRET && _validNickname(buff) && !buff.empty()) {
			this->_contact[this->_idx].setValues(buff, SECRET);
			break;
		} else if (buff.empty()) {
			std::cout << "Field can not be empty." << std::endl;
		} else {
			std::cout << "Invalid input." << std::endl;
		}
	}
}

void PhoneBook::_addNames(const std::string field) {

	std::string buff;

	while (true) {

		std::cout << field;
		std::getline(std::cin, buff);
		if (_validString(buff) && !buff.empty()) {
			if (field == FNAME) {
				this->_contact[this->_idx].setValues(buff, FNAME);
			} else if (field == LNAME) {
				this->_contact[this->_idx].setValues(buff, LNAME);
			}
			break;
		} else if (buff.empty()) {
			std::cout << "Field can not be empty." << std::endl;
		} else {
			std::cout << "Invalid name." << std::endl;
		}
	}
}

std::string PhoneBook::_truncate(std::string str, size_t width) const {

	std::string truncated;

	truncated = str;
	if (str.length() > width) {
		truncated = str.replace(9, str.length(), ".");
	}
	return (truncated);
}

void PhoneBook::_listContacts() const {

	std::string firstName;
	std::string lastName;
	std::string nickname;

	std::cout << std::setw(FWIDTH) << std::left << "Index" << " | ";
	std::cout << std::setw(FWIDTH) << std::left << "First Name" << " | ";
	std::cout << std::setw(FWIDTH) << std::left << "Last Name" << " | ";
	std::cout << std::setw(FWIDTH) << std::left << "Nickname" << std::endl;
	for (int i = 0; i < this->_nbrElements; i++) {
		std::cout << std::setw(FWIDTH) << std::left << i + 1 << " | ";
		firstName = this->_contact[i].getValues(FNAME);
		lastName = this->_contact[i].getValues(LNAME);
		nickname = this->_contact[i].getValues(NICK);

		firstName = this->_truncate(this->_contact[i].getValues(FNAME), FWIDTH);
		lastName = this->_truncate(this->_contact[i].getValues(LNAME), FWIDTH);
		nickname = this->_truncate(this->_contact[i].getValues(NICK), FWIDTH);

		std::cout << std::setw(FWIDTH) << std::left << firstName << " | ";
		std::cout << std::setw(FWIDTH) << std::left << lastName << " | ";
		std::cout << std::setw(FWIDTH) << std::left << nickname << std::endl;
	}
	return;
}

void PhoneBook::searchContacts() const {

	std::string buff;
	int			idx;

	std::cout << std::left;
	this->_listContacts();
	while (true) {

		std::cout << SEARCH << std::endl;
		std::getline(std::cin, buff);
		if (buff == "q") {
			return;
		}
		if (this->_validNumber(buff)) {
			std::istringstream(buff) >> idx;
			if (idx > 0 && idx <= this->_nbrElements) {
				break;
			} else {
				std::cout << NOIDX << std::endl;
			}
		} else {
			std::cout << BADNBR << std::endl;
		}
	}
	idx--;
	std::cout << "Openning contact number " << idx + 1 << std::endl;
	std::cout << std::setw(FWIDTH) << FNAME << this->_contact[idx].getValues(FNAME) << std::endl;
	std::cout << std::setw(FWIDTH) << LNAME << this->_contact[idx].getValues(LNAME) << std::endl;
	std::cout << std::setw(FWIDTH) << NICK << this->_contact[idx].getValues(NICK) << std::endl;
	std::cout << std::setw(FWIDTH) << PHONE << this->_contact[idx].getValues(PHONE) << std::endl;
	std::cout << std::setw(FWIDTH) << SECRET << this->_contact[idx].getValues(SECRET) << std::endl;
	return;
}
