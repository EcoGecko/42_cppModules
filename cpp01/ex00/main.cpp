/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:44:47 by heda-sil          #+#    #+#             */
/*   Updated: 2023/09/23 12:06:08 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void	randomChump(std::string name);

int main(void) {

	Zombie *zombie1 = newZombie("Zombie1");
	Zombie *zombie2 = newZombie("Zombie2");
	Zombie *zombie3 = newZombie("Zombie3");
	Zombie *zombie4 = newZombie("Zombie4");
	Zombie *zombie5 = newZombie("Zombie5");

	zombie1->announce();
	zombie2->announce();
	zombie3->announce();
	zombie4->announce();
	zombie5->announce();
	delete zombie1;
	delete zombie2;
	delete zombie3;
	delete zombie4;
	delete zombie5;

	randomChump("Zombie6");
	randomChump("Zombie7");
	randomChump("Zombie8");
	randomChump("Zombie9");
	randomChump("Zombie10");

	return (0);
}
