/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 10:23:17 by heda-sil          #+#    #+#             */
/*   Updated: 2024/01/23 14:50:35 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>
# define BOLD "\033[1m"
# define RESET "\033[0m"
# define RED "\033[31m"

int main(void) {
	try {
		Bureaucrat man("Helder", 25);
		Form	   trip("Trip", 150, 125);
		Form	   work("Work", 150, 125);
		Form	   bank("Bank", 150, 125);

		man.signForm(trip);
		man.signForm(work);
		std::cout << trip << std::endl;
		std::cout << work << std::endl;
		std::cout << bank << std::endl;

		Form	house;

		std::cout << house << std::endl;
		house = work;
		std::cout << house << std::endl;
		man.signForm(house);
	} catch (const std::exception &e) {
		std::cerr << BOLD << RED << e.what() << RESET << '\n';
	}
}
