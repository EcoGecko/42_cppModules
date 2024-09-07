/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:19:26 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/27 14:11:06 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void) {

	ScavTrap Bob("Bob");
	ScavTrap Harold("Harold");
	ScavTrap Bub(Bob);

	Bob.attack("a biter");
	Bob.takeDamage(9);
	Bob.beRepaired(5);
	Bob.takeDamage(7);
	Bob.beRepaired(5);
	Bob.guardGate();
	Harold.attack("a spiter");
}
