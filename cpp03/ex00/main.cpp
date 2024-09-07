/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:19:26 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/27 13:28:58 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {

	ClapTrap Bob("Bob");
	ClapTrap Harold("Harold");
	ClapTrap Bub(Bob);

	Bob.attack("a biter");
	Bob.takeDamage(9);
	Bob.beRepaired(5);
	Bob.takeDamage(7);
	Bob.beRepaired(5);
	Harold.attack("a spiter");
	Harold.takeDamage(9);
	Harold.beRepaired(5);
	Harold.takeDamage(7);
	Harold.beRepaired(5);
}
