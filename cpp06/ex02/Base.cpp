

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

Base::~Base(void) {
}

Base	*generate(void) {
	std::srand(time(NULL));

	int rand = std::rand() % 3;
	switch (rand) {
		case 0:
			std::cout << "Generated type A pointer" << std::endl;
			return (new A);
		case 1:
			std::cout << "Generated type B pointer" << std::endl;
			return (new B);
		case 2:
			std::cout << "Generated type C pointer" << std::endl;
			return (new C);
		default:
			std::cout << "Unknown type pointer" << std::endl;
			return (NULL);
	}
}

void	identify(Base *p) {
	if (dynamic_cast<A *>(p)) {
		std::cout << "Identified type A pointer" << std::endl;
	} else if (dynamic_cast<B *>(p)) {
		std::cout << "Identified type B pointer" << std::endl;
	} else if (dynamic_cast<C *>(p)) {
		std::cout << "Identified type C pointer" << std::endl;
	} else {
		std::cout << "Unknown type pointer" << std::endl;
	}
}

void	identify(Base &p) {
	try {
		Base &tmp = dynamic_cast<A &>(p);
		(void)tmp;
		std::cout << "Identified type A reference" << std::endl;
	} catch (std::exception &e) {
		try {
			Base &tmp = dynamic_cast<B &>(p);
			(void)tmp;
			std::cout << "Identified type B reference" << std::endl;
		} catch (std::exception &e) {
			try {
				Base &tmp = dynamic_cast<C &>(p);
				(void)tmp;
				std::cout << "Identified type C reference" << std::endl;
			} catch (std::exception &e) {
				std::cout << "Unknown type reference" << std::endl;
			}
		}
	}
}
