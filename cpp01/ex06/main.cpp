/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:28:24 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/04 13:01:43 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv) {

	Harl	harl;

	if (argc != 2) {
		std::cerr << "Usage: ./Harl <COMPLAIN LEVEL>" << std::endl;
		return (1);
	}
	std::string	input (argv[1]), level[4];
	
	level[0] = "DEBUG";
	level[1] = "INFO";
	level[2] = "WARNING";
	level[3] = "ERROR";

	int	key = 0;
	for (int i = 0; i < 4; i++) {
		if (input == level[i]) {
			key = i + 1;
			break ;
		}
	}
	switch (key) {
		case 1:
			std::cout << "[ DEBUG ]" << std::endl;
			harl.complain("DEBUG");
		case 2:
			std::cout << "[ INFO ]" << std::endl;
			harl.complain("INFO");
		case 3:
			std::cout << "[ WARNING ]" << std::endl;
			harl.complain("WARNING");
		case 4	:
			std::cout << "[ ERROR ]" << std::endl;
			harl.complain("ERROR");
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
