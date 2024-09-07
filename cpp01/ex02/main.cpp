/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:09:08 by heda-sil          #+#    #+#             */
/*   Updated: 2023/09/22 16:14:15 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void) {
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "The memory adress of string is: " << &str << std::endl;
	std::cout << "The memory adress of stringPTR is: " << &stringPTR << std::endl;
	std::cout << "The memory adress of stringREF is: " << &stringREF << std::endl;
	std::cout << "The value of the string is: " << str << std::endl;
	std::cout << "The value pointed to by stringPTR is: " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF is: " << stringREF << std::endl;
}
