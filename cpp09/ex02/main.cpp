#include "PmergeMe.hpp"
#include <iostream>
#include <list>
#include <vector>

template <typename T>
void print(T &t) {
	for (typename T::iterator it = t.begin(); it != t.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char **argv) {
	PmergeMe		 pm;
	std::vector<int> vec;
	std::list<int>	 lst;

	if (argc < 2) {
		std::cout << "Usage: ./PmergeMe \"<sequence>\"" << std::endl;
		return (1);
	}
	if (!pm.parsing(argv + 1, vec, lst)) {
		std::cout << "Error" << std::endl;
		return (1);
	}
	std::cout << "Before: " << std::endl;
	print(vec);
	double vecTime = pm.mergeInsertionSort(vec);
	double lstTime = pm.mergeInsertionSort(lst);

	std::cout << "After: " << std::endl;
	std::cout << "Vector: " << std::endl;
	print(vec);
	std::cout << "List: " << std::endl;
	print(lst);

	std::cout << "Time to process a range of " << vec.size()
			  << " elements with std::vector : " << vecTime * 1e6 << " µs or "
			  << vecTime << " seconds" << std::endl;
	std::cout << "Time to process a range of " << lst.size()
			  << " elements with std::list : " << lstTime * 1e6 << " µs or "
			  << lstTime << " seconds" << std::endl;
	return (0);
}
