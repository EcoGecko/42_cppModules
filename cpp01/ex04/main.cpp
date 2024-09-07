/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heda-sil <heda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:54:21 by heda-sil          #+#    #+#             */
/*   Updated: 2023/10/04 12:48:53 by heda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

std::string	replaceSed(std::string &fileBuff, std::string const &s1, std::string const &s2) {

	std::string	replaced;

	int pos = 0;
	while (pos >= 0) {
		pos = fileBuff.find(s1, pos);
		if (pos < 0) {
			break ;
		}
		fileBuff.erase(pos, s1.length());
		fileBuff.insert(pos, s2);
		pos += s2.length();
	}
	replaced = fileBuff;
	return (replaced);
}

std::string	readFile(char *infile) {

	std::ifstream	inFile(infile);
	std::string		fileContent;

	if (!inFile.is_open()) {
		std::cerr << "Error opening file." << std::endl;
		return (fileContent);
	}

	std::ostringstream	buff;

	buff << inFile.rdbuf();
	fileContent = buff.str();
	inFile.close();
	return (fileContent);
}

int main(int argc, char *argv[]) {

	if (argc != 4) {
		std::cerr << "Wrong number of arguments." << std::endl;
		std::cout << "Usage: ./sed <filename> <string1> <string2>" << std::endl;
		return (1);
	}
	std::string		outFileName(argv[1]);
	std::string		fileBuff;

	outFileName.append(".replace");
	fileBuff = readFile(argv[1]);
	if (fileBuff.empty()) {
		return (1);
	}
	std::ofstream	outFile;

	outFile.open(outFileName.c_str());
	outFile << replaceSed(fileBuff, std::string(argv[2]), std::string(argv[3]));
	outFile.close();
	return (0);
}
