/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 10:23:17 by heda-sil          #+#    #+#             */
/*   Updated: 2024/01/23 17:53:43 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>
# define BOLD "\033[1m"
# define RESET "\033[0m"
# define RED "\033[31m"

int main(void) {
	std::cout << BOLD << "==========Test 1==========" << RESET << std::endl;
	try {
		Bureaucrat b1("Helder", 1);
		AForm	  *Shrubbery = new ShrubberyCreationForm("test");

		std::cout << ">Signing..." << std::endl;
		b1.signForm(*Shrubbery);
		std::cout << "\n>Executing..." << std::endl;
		b1.executeForm(*Shrubbery);
		delete Shrubbery;

		AForm	*Robotomy = new RobotomyRequestForm("Joe");

		std::cout << "\n>Signing..." << std::endl;
		b1.signForm(*Robotomy);
		std::cout << "\n>Executing..." << std::endl;
		b1.executeForm(*Robotomy);
		delete Robotomy;

		AForm	*pardon = new PresidentialPardonForm("Joe");

		std::cout << "\n>Signing..." << std::endl;
		b1.signForm(*pardon);
		std::cout << "\n>Executing..." << std::endl;
		b1.executeForm(*pardon);
		delete pardon;

		AForm	*notSign = new RobotomyRequestForm("Moe");

		std::cout << "\n>Executing..." << std::endl;
		b1.executeForm(*notSign);
	} catch (std::exception &e) {
		std::cerr << BOLD << RED << e.what() << std::endl;
	}
	std::cout << BOLD << "==========Test 2==========" << RESET << std::endl;
	try {
		Bureaucrat b1("Helder", 150);
		AForm	  *Shrubbery = new ShrubberyCreationForm("test");

		std::cout << ">Signing..." << std::endl;
		b1.signForm(*Shrubbery);
		std::cout << "\n>Executing..." << std::endl;
		b1.executeForm(*Shrubbery);
		delete Shrubbery;

		AForm	*Robotomy = new RobotomyRequestForm("Joe");

		std::cout << "\n>Signing..." << std::endl;
		b1.signForm(*Robotomy);
		std::cout << "\n>Executing..." << std::endl;
		b1.executeForm(*Robotomy);
		delete Robotomy;

		AForm	*pardon = new PresidentialPardonForm("Joe");

		std::cout << "\n>Signing..." << std::endl;
		b1.signForm(*pardon);
		std::cout << "\n>Executing..." << std::endl;
		b1.executeForm(*pardon);
		delete pardon;

		AForm	*notSign = new RobotomyRequestForm("Moe");

		std::cout << "\n>Executing..." << std::endl;
		b1.executeForm(*notSign);
		delete notSign;
	} catch (std::exception &e) {
		std::cerr << BOLD << RED << e.what() << std::endl;
	}
}
