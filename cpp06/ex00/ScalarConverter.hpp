/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:56:55 by heda-sil          #+#    #+#             */
/*   Updated: 2024/01/27 20:40:41 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <cstdlib>
#include <iostream>
#include <string>

class ScalarConverter {

public:
	static void convert(std::string const &literal);

private:
	ScalarConverter(void);
	ScalarConverter(ScalarConverter const &obj);

	ScalarConverter &operator=(ScalarConverter const &obj);

	~ScalarConverter(void);

	static bool isChar(std::string const &literal);
	static bool isInt(std::string const &literal);
	static bool isFloat(std::string const &literal);
	static bool isDouble(std::string const &literal);
	static bool isPseudo(std::string const &literal);
	static bool isValid(std::string const &literal);
	static void convertLiteral(std::string const &literal);
	static void convertChar(char c);
	static void convertInt(int i);
	static void converFloat(float f);
	static void convertDouble(double d);
	static void convertPseudo(std::string const &literal);
};

#endif
