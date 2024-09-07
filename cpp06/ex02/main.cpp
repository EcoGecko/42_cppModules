

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main(void) {
	Base	*base = generate();
	Base	*BaseA = new A;
	Base	*BaseB = new B;
	Base	*BaseC = new C;

	std::cout << "\nIdentifying a Base A type pointer...\n" ;
	identify(BaseA);
	std::cout << "\nIdentifying a Base B type pointer...\n" ;
	identify(BaseB);
	std::cout << "\nIdentifying a Base C type pointer...\n" ;
	identify(BaseC);
	std::cout << "\nIdentifying a random generated Base type pointer...\n" ;
	identify(base);
	std::cout << "\nIdentifying a Base A type reference...\n" ;
	identify(*BaseA);
	std::cout << "\nIdentifying a Base B type reference...\n" ;
	identify(*BaseB);
	std::cout << "\nIdentifying a Base C type reference...\n" ;
	identify(*BaseC);
	std::cout << "\nIdentifying a random generated Base type reference...\n";
	identify(*base);

	delete BaseA;
	delete BaseB;
	delete BaseC;
	delete base;
	return (0);
}
