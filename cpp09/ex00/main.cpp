

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char** argv) {
	BitcoinExchange exchange;

	if (argc != 2) {
		std::cerr << BAD_FILE << std::endl;
		return (1);
	}
	if (!exchange.convert(argv[1])) {
		std::cerr << BAD_FILE << std::endl;
		return (1);
	}
	return (0);
}
