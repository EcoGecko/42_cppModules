#include "Span.hpp"

void testFromSubject(void) {
	Span sp = Span(5);

	std::cout << BOLD "\n\n==========Subject==========\n\n" RESET;
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "-----Container-----\n" << sp << "-------------------\n\n";
	std::cout << sp.shortestSpan() << "\n";
	std::cout << sp.longestSpan() << "\n";
}

void testFill(void) {
	Span sp = Span(10);
	int	 sign = 1;

	if (std::rand() % 2)
		sign = -1;

	int a = std::rand() % 1000;
	int b = sign * std::rand() % 1000;

	std::cout << BOLD "\n\n==========Testing fill==========\n" RESET;
	std::cout << BOLD "a: " RESET << a << BOLD " b: " RESET << b << std::endl;
	try {
		sp.fill(a, b);
		std::cout << "-----Container-----\n" << sp << "-------------------\n\n";
		try {
			sp.addNumber(42);
			sp.addNumber(84);
		} catch (std::exception &e) {
			std::cout << BOLD RED << e.what() << RESET << std::endl;
		}
		std::cout << BOLD "Shortest span: " RESET << sp.shortestSpan() << "\n";
		std::cout << BOLD "Longest span: " RESET << sp.longestSpan() << "\n";
	} catch (std::exception &e) {
		std::cout << BOLD RED << e.what() << RESET << std::endl;
	}
}

void	testSpans(void) {
	Span sp = Span(1);

	std::cout << BOLD "\n\n==========Testing spans==========\n" RESET;
	try {
		sp.fill(0, 10);
		std::cout << "-----Container-----\n" << sp << "-------------------\n\n";
		std::cout << sp.shortestSpan() << "\n";
		std::cout << sp.longestSpan() << "\n";
	}
	catch (std::exception &e) {
		std::cerr << BOLD RED << e.what() << RESET << std::endl;
	}
}

void	testConstructors(void) {
	Span sp = Span(10);

	std::cout << BOLD "\n\n==========Testing constructors=========\n" RESET;
	std::cout << "Adding a number to the original span...\n";
	sp.addNumber(10);

	std::cout << "Assigning to a copy span...\n";
	Span spAssign = sp;
	std::cout << "Adding a number to the assignned span...\n";
	spAssign.addNumber(11);

	std::cout << "Constructing using original span...\n";
	Span spCopy = Span(sp);
	std::cout << "Adding a number to the constructed span...\n";
	spCopy.addNumber(12);

	std::cout << BOLD "=====Original span=====\n" RESET;
	std::cout << sp << std::endl;
	std::cout << BOLD "=====Assignned span=====\n" RESET;
	std::cout << spAssign << std::endl;
	std::cout << BOLD "=====Constructed span=====\n" RESET;
	std::cout << spCopy << std::endl;
}

int main(void) {
	std::srand(std::time(NULL));

	testFill();
	testSpans();
	testFromSubject();
	testConstructors();
	return (0);
}
