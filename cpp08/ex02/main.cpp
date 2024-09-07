

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <algorithm>

template <typename T>
void	testCustom(std::string const &container) {
	std::cout << "\nTesting with " << container << "...\n";

	T mstack;

	mstack.push_back(5);
	mstack.push_back(17);

	std::cout << "First element: " << mstack.back() << "\n";

	mstack.pop_back();

	std::cout << "Size:" << mstack.size() << "\n";

	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);

	typename T::iterator it  = mstack.begin();
	typename T::iterator ite = mstack.end();

	std::cout << "Nbr of 5's: " << std::count(mstack.begin(), mstack.end(), 5) << "\n";

	++it;
	--it;
	while (it != ite) {
		std::cout << *it << "\n";
		++it;
	}
}

template<typename T>
void	testSubject(void) {
	MutantStack<T> mstack;

	std::cout << "\nTesting with Mutant stack...\n";

	mstack.push(5);
	mstack.push(17);

	std::cout << "First element: " << mstack.top() << "\n";

	mstack.pop();

	std::cout << "Size:" << mstack.size() << "\n";

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	typename MutantStack<T>::iterator it  = mstack.begin();
	typename MutantStack<T>::iterator ite = mstack.end();

	std::cout << "Nbr of 5's: " << std::count(mstack.begin(), mstack.end(), 5) << "\n";

	++it;
	--it;
	while (it != ite) {
		std::cout << *it << "\n";
		++it;
	}
	std::stack<T> s(mstack);
}

int main(void) {
	testSubject<int>();
	testCustom<std::list<int> >("list");
	testCustom<std::vector<int> >("vector");
	testCustom<std::deque<int> >("deque");
	return 0;
}
