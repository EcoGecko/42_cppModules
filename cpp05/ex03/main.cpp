/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 10:23:17 by heda-sil          #+#    #+#             */
/*   Updated: 2024/01/23 16:01:48 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>
#include <iostream>
# define BOLD "\033[1m"
# define RESET "\033[0m"
# define RED "\033[31m"

int main(void) {
	try {
		Bureaucrat b1("Helder", 30);
		Intern	   intern;
		AForm	  *form;

		form = intern.makeForm("robotomy request", "Bender");
		std::cout << '\n' << *form << std::endl;
		std::cout << "\n>Signing..." << std::endl;
		b1.signForm(*form);
		std::cout << "\n>Executing..." << std::endl;
		b1.executeForm(*form);
		delete form;

		std::cout << '\n';
		form = intern.makeForm("presidential pardon", "Bender");
		std::cout << '\n' << *form << std::endl;
		std::cout << "\n>Executing..." << std::endl;
		b1.executeForm(*form);
		delete form;

	} catch (std::exception &e) {
		std::cerr << BOLD << RED << e.what() << RESET << std::endl;
	}
}
