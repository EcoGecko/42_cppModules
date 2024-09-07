#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
	RPN rpn;

	if (argc == 2) {
		rpn.run(argv[1]);
	} else {
		std::cout << "Usage: ./rpn \"<expression>\"" << std::endl;
	}
	return (0);
}
