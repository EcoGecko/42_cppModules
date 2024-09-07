/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 19:14:19 by heda-sil          #+#    #+#             */
/*   Updated: 2023/12/29 19:15:16 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: ./convert [literal]" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
