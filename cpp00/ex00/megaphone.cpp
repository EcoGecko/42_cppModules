/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:21:56 by heda-sil          #+#    #+#             */
/*   Updated: 2023/09/21 11:44:04 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char *argv[]) {

	int			i;
	std::string str;

	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	i = 0;
	while (++i < argc) {

		str = argv[i];
		for (size_t j = 0; j <= str.length(); j++) {
			
			str[j] = std::toupper(str[j]);
		}
		std::cout << str;
	}
	std::cout << std::endl;
	return (0);
}
