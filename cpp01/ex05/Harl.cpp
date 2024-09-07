/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:28:33 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/04 12:56:43 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#define DEBUG "I love having extra bacon for my 7XL-double-cheese-triple-pickle\
-special-ketchup burger. I really do!"
#define INFO "I cannot believe adding extra bacon costs more money. You didn’t \
put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
#define WARNING "I think I deserve to have some extra bacon for free. I’ve been\
coming for years whereas you started working here since last month."
#define ERROR "This is unacceptable! I want to speak to the manager now."

Harl::Harl() {
}

Harl::~Harl() {
}

void	Harl::complain(std::string level) {

	void (Harl::*harlFuncs[4])();
	harlFuncs[0] = &Harl::debug;
	harlFuncs[1] = &Harl::info;
	harlFuncs[2] = &Harl::warning;
	harlFuncs[3] = &Harl::error;

	std::string	levels[4];
	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";

	for (int i = 0; i < 4; i++) {
		if (level == levels[i]) {
			(this->*harlFuncs[i])();
		}
	}
}

void	Harl::debug() {
	std::cout << DEBUG << std::endl;
}

void	Harl::info() {
	std::cout << INFO << std::endl;
}

void	Harl::warning() {
	std::cout << WARNING << std::endl;
}

void	Harl::error() {
	std::cout << ERROR << std::endl;
}
