#include "RPN.hpp"
#include <cstdlib>
#include <iostream>
#include <sstream>

RPN::RPN(void) {
}

RPN::RPN(RPN const &obj) {
	*this = obj;
}

RPN &RPN::operator=(RPN const &rhs) {
	if (this == &rhs) {
		return (*this);
	}
	this->stack = rhs.stack;
	return (*this);
}

RPN::~RPN(void) {
}

bool RPN::isValidChar(char c) {
	return (c == '/' || c == '*' || c == '-' || c == '+' ||
			(c >= '0' && c <= '9'));
}

bool RPN::isValidInput(std::string const &str) {
	size_t	chars = 0;

	for (size_t i = 0; i < str.size(); ++i) {
		if (str[i] == ' ') {
			continue;
		}
		chars++;
		if (!this->isValidChar(str[i])) {
			std::cerr << ERR_SYMBOL << ": " << str[i] << std::endl;
			return (false);
		}
	}
	if (chars < 3) {
		std::cerr << ERR_INPUT << std::endl;
		return (false);
	}
	return (true);
}

enum e_op RPN::parseInput(std::string &str) {
	if (str == "/") {
		return (DIV);
	} else if (str == "*") {
		return (MULT);
	} else if (str == "-") {
		return (SUB);
	} else if (str == "+") {
		return (SUM);
	} else if (std::isdigit(str[0]) && str.size() == 1) {
		return (DIGIT);
	}
	return (ERROR);
}

void RPN::doOperation(int &a, int &b, enum e_op op) {
	switch (op) {
	case (0):
		this->stack.push(a / b);
		break;
	case (1):
		this->stack.push(a * b);
		break;
	case (2):
		this->stack.push(a - b);
		break;
	case (3):
		this->stack.push(a + b);
		break;
	default:
		std::cerr << ERR_OPERATION << std::endl;
		return;
	}
}

void RPN::print() {
	for (size_t i = 0; i <= this->stack.size(); ++i) {
		std::cout << this->stack.top() << std::endl;
		this->stack.pop();
	}
}

void RPN::run(std::string const &str) {
	if (!this->isValidInput(str)) {
		return;
	}

	std::istringstream stream(str);
	std::string		   rawOp;
	enum e_op		   op;

	while (!stream.eof()) {
		std::getline(stream, rawOp, ' ');
		if (rawOp.empty()) {
			continue;
		}
		op = this->parseInput(rawOp);
		if (op == DIGIT) {
			this->stack.push(std::atoi(rawOp.c_str()));
			continue;
		}
		if (this->stack.size() < 2) {
			std::cerr << ERR_INPUT << std::endl;
			return;
		}
		int b = this->stack.top();
		this->stack.pop();
		int a = this->stack.top();
		this->stack.pop();
		this->doOperation(a, b, op);
	}
	if (this->stack.size() != 1) {
		std::cerr << ERR_STACK << std::endl;
		return;
	}
	std::cout << this->stack.top() << std::endl;
}
