/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 19:56:57 by heda-sil          #+#    #+#             */
/*   Updated: 2024/01/30 14:54:32 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cmath>
#include <limits>

ScalarConverter::ScalarConverter(void) {
}

ScalarConverter::ScalarConverter(ScalarConverter const &obj) {
	*this = obj;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &obj) {
	if (this == &obj) {
		return (*this);
	}
	return (*this);
}

ScalarConverter::~ScalarConverter(void) {
}

void ScalarConverter::convert(std::string const &literal) {
	if (isPseudo(literal)) {
		convertPseudo(literal);
	} else if (isValid(literal)) {
		convertLiteral(literal);
	} else {
		std::cout << "UNKNOWN TYPE" << std::endl;
	}
}

void ScalarConverter::convertLiteral(std::string const &literal) {
	if (isChar(literal)) {
		convertChar(static_cast<char>(literal.c_str()[0]));
		convertInt(static_cast<int>(literal.c_str()[0]));
		converFloat(static_cast<float>(literal.c_str()[0]));
		convertDouble(static_cast<double>(literal.c_str()[0]));
	} else {
		convertChar(static_cast<char>(std::strtol(literal.c_str(), NULL, 10)));
		long	tmp = std::strtol(literal.c_str(), NULL, 10);
		if (tmp > std::numeric_limits<int>::max()) {
			std::cout << "Int: Positive Overflow" << std::endl;
		} else if (tmp < std::numeric_limits<int>::min()) {
			std::cout << "Int: Negative Overflow" << std::endl;
		} else {
			convertInt(static_cast<int>(tmp));
		}
		converFloat(static_cast<float>(std::strtof(literal.c_str(), NULL)));
		convertDouble(static_cast<double>(std::strtod(literal.c_str(), NULL)));
	}
}

/* Deals with the pseudo values */
void ScalarConverter::convertPseudo(const std::string &literal) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (literal.find("nan") != std::string::npos) {
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	} else {
		std::cout << "float: " << literal[0] << "inff" << std::endl;
		std::cout << "double: " << literal[0] << "inf" << std::endl;
	}
}

void ScalarConverter::convertInt(int i) {
	std::cout << "int: " << i << std::endl;
}

void ScalarConverter::converFloat(float f) {
	if (std::fmod(f, 1.0f) == 0) {
		std::cout.precision(1);
		std::cout << "float: " << std::fixed << f << "f" << std::endl;
	} else {
		std::cout << "float: " << f << "f" << std::endl;
	}
}

void ScalarConverter::convertDouble(double d) {
	if (std::fmod(d, 1.0) == 0) {
		std::cout.precision(1);
		std::cout << "double: " << std::fixed << d << std::endl;
	} else {
		std::cout << "double: " << std::fixed << d << std::endl;
	}
}

void ScalarConverter::convertChar(char c) {
	std::cout << "char: ";
	if (std::isprint(c)) {
		std::cout << "'" << c << "'" << std::endl;
	} else {
		std::cout << "Non displayable" << std::endl;
	}
}

/* Checks if string literal is a char */
bool ScalarConverter::isChar(std::string const &literal) {
	return (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]));
}

/* Checks if string literal is an INT */
bool ScalarConverter::isInt(std::string const &literal) {
	size_t signal = literal.find('-');
	size_t index = 0;

	if (signal != 0 && signal != std::string::npos) {
		return (false);
	} else if (signal == 0) {
		index = 1;
	}
	for (size_t i = index; i < literal.size(); i++) {
		if (!std::isdigit(literal[i])) {
			return (false);
		}
	}
	return (true);
}

/* Checks if string literal is a FLOAT */
bool ScalarConverter::isFloat(std::string const &literal) {
	size_t signal = literal.find('-');
	size_t index = 0;
	size_t dot = 0;

	if (signal != 0 && signal != std::string::npos) {
		return (false);
	} else if (signal == 0) {
		index = 1;
	}
	if (literal.find('f', literal.size() - 1) == std::string::npos) {
		return (false);
	}
	for (size_t i = index; i < literal.size() - 1; i++) {
		if (literal[i] == '.') {
			dot++;
		} else if (!std::isdigit(literal[i])) {
			return (false);
		}
	}
	return (dot == 1);
}

/* Checks if string literal is a DOUBLE */
bool ScalarConverter::isDouble(std::string const &literal) {
	size_t signal = literal.find('-');
	size_t index = 0;
	size_t dot = 0;

	if (signal != 0 && signal != std::string::npos) {
		return (false);
	} else if (signal == 0) {
		index = 1;
	}
	for (size_t i = index; i < literal.size() - 1; i++) {
		if (literal[i] == '.') {
			dot++;
		} else if (!std::isdigit(literal[i])) {
			return (false);
		}
	}
	return (dot == 1);
}

/* Checks if string literal is any of the pseudo-science */
bool ScalarConverter::isPseudo(std::string const &literal) {
	return (literal == "nan" || literal == "nanf" || literal == "+inf" ||
			literal == "+inff" || literal == "-inf" || literal == "-inff");
}

/* Checks if string literal is valid for conversion */
bool ScalarConverter::isValid(std::string const &literal) {
	return (isChar(literal) || isInt(literal) || isFloat(literal) || isDouble(literal));
}
