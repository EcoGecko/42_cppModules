/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:04:00 by heda-sil          #+#    #+#             */
/*   Updated: 2023/09/22 20:27:34 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#define NBR_ZOMBIES 50

Zombie *zombieHorde(int N, std::string name);

int main(void) {

	Zombie *zombies = zombieHorde(NBR_ZOMBIES, "Zombie");

	for (int i = 0; i < NBR_ZOMBIES; i++)
	{
		zombies[i].announce();
	}

	delete[] zombies;

	return 0;
}
