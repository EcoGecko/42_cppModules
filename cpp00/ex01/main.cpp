/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:20:30 by heda-sil          #+#    #+#             */
/*   Updated: 2023/09/21 13:41:16 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>

#include "PhoneBook.hpp"

int main(void) {

	PhoneBook	list;
	std::string buff;

	while (true) {

		std::cout << "Enter the desired operation (ADD, SEARCH or EXIT): ";
		std::cin.clear();
		if (std::getline(std::cin, buff)) {
			if (buff == "ADD") {
				list.addContact();
				std::cout << "Contact added" << std::endl;
			} else if (buff == "SEARCH") {
				list.searchContacts();
			} else if (buff == "EXIT") {
				return (0);
			} else if (!buff.empty()) {
				std::cout << "Invalid operation." << std::endl;
			}
		} else {
			std::cout << std::endl;
			return (0);
		}
	}
	return (0);
}
