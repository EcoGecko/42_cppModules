/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:19:26 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/30 12:54:34 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void) {

	DiamondTrap Bob("Bob");
	DiamondTrap Harold("Harold");

	Bob.attack("a biter");
	Bob.takeDamage(9);
	Bob.beRepaired(5);
	Bob.takeDamage(7);
	Bob.beRepaired(5);
	Bob.highFivesGuys();
	Bob.guardGate();
	Harold.attack("a spiter");
	Harold.takeDamage(9);
	Harold.beRepaired(5);
	Harold.takeDamage(7);
	Harold.beRepaired(5);
	Harold.highFivesGuys();
	Harold.whoAmI();
}
