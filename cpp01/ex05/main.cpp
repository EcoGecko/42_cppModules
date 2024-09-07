/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:28:24 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/03 15:43:35 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv) {
	Harl	harl;

	if (argc != 2) {
		std::cerr << "Usage: ./Harl <COMPLAIN LEVEL>" << std::endl;
		return (1);
	}
	harl.complain(argv[1]);
}
