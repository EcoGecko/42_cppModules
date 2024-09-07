/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 10:23:17 by heda-sil          #+#    #+#             */
/*   Updated: 2024/01/23 13:50:29 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"
# define BOLD "\033[1m"
# define RESET "\033[0m"
# define RED "\033[31m"


int	main(void) {
	std::cout << BOLD << "\n==========Test 1==========" << RESET << std::endl;
	try {
		Bureaucrat man("Helder", 150);

		std::cout << man << std::endl;
		std::cout << "\nIncrementing Grade..." << std::endl;
		man.incrementGrade();
		std::cout << man << std::endl;
		std::cout << "\nDecrementing Grade..." << std::endl;
		man.decrementGrade();
		std::cout << man << std::endl;

		Bureaucrat man2("Filipe", 1);

		std::cout << '\n' << man2 << std::endl;
		std::cout << "\nCopying..." << std::endl;
		man2 = man;
		std::cout << man << std::endl;
		std::cout << man2 << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << BOLD << RED << e.what() << RESET << std::endl;
	}
	std::cout << BOLD << "\n==========Test 2==========" << RESET << std::endl;
	try {
		Bureaucrat man("Helder", 1);

		std::cout << man << std::endl;
		std::cout << "Incrementing Grade..." << std::endl;
		man.incrementGrade();
		std::cout << man << std::endl;
		std::cout << "Decrementing Grade..." << std::endl;
		man.decrementGrade();
		std::cout << man << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << BOLD << RED << e.what() << RESET << std::endl;
	}
	std::cout << BOLD << "\n==========Test 3==========" << RESET << std::endl;
	try {
		Bureaucrat man("Helder", 160);

		std::cout << man << std::endl;
		std::cout << "Incrementing Grade..." << std::endl;
		man.incrementGrade();
		std::cout << man << std::endl;
		std::cout << "Decrementing Grade..." << std::endl;
		man.decrementGrade();
		std::cout << man << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << BOLD << RED << e.what() << RESET << std::endl;
	}
}
