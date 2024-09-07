/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:24:48 by heda-sil          #+#    #+#             */
/*   Updated: 2024/01/23 15:56:13 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void) {
}

Intern::Intern(Intern const &obj) {
	*this = obj;
}

Intern &Intern::operator=(Intern const &obj) {
	if (this == &obj) {
		return (*this);
	}
	return (*this);
}

Intern::~Intern(void) {
}

AForm *Intern::makeForm(std::string const form, std::string const target) {
	std::string formType[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	int key = -1;

	for (int i = 0; i < 3; i++) {
		if (form == formType[i]) {
			key = i;
			break;
		}
	}

	switch (key)
	{
	case 0:
		std::cout << "Intern creates " << form << std::endl;
		return (new PresidentialPardonForm(target));
	case 1:
		std::cout << "Intern creates " << form << std::endl;
		return (new RobotomyRequestForm(target));
	case 2:
		std::cout << "Intern creates " << form << std::endl;
		return (new ShrubberyCreationForm(target));
	default:
		throw Intern::FormNotFoundException();
	}
}

const char *Intern::FormNotFoundException::what() const throw(){
	return ("\nForm not found\n");
}
