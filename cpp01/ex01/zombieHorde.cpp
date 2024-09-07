/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:56:26 by heda-sil          #+#    #+#             */
/*   Updated: 2023/08/24 13:15:35 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {

	Zombie *zombies = new Zombie[N];

	for (int i = 0; i < N; i++) {
		zombies[i].setName(name);
	}

	return (zombies);
}
