

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <limits>

template<typename T>
void testEasyfind(T &container, std::string const &type, int value) {
	container.push_back(9);
	container.push_back(10);
	container.push_back(0);
	container.push_back(50);
	container.push_back(std::numeric_limits<int>::max());
	container.push_back(std::numeric_limits<int>::min());

	int pos = easyfind(container, value);
	if (pos == -1) {
		std::cout << "Could not find " << value << " in " << type << std::endl;
	} else {
		std::cout << "Found " << value << " at position " << pos << " of the "
				  << type << std::endl;
	}
}

int main(void) {
	std::vector<int> vec;
	std::list<int>   list;
	std::deque<int>  deque;

	testEasyfind(vec, "vector", 9);
	testEasyfind(vec, "vector", 0);
	testEasyfind(vec, "vector", -10);
	testEasyfind(vec, "vector", 8);
	testEasyfind(vec, "vector", std::numeric_limits<int>::max());
	testEasyfind(list, "List", 9);
	testEasyfind(list, "List", 0);
	testEasyfind(list, "List", -10);
	testEasyfind(list, "List", 8);
	testEasyfind(list, "List", std::numeric_limits<int>::max());
	testEasyfind(deque, "Deque", 9);
	testEasyfind(deque, "Deque", 0);
	testEasyfind(deque, "Deque", -10);
	testEasyfind(deque, "Deque", 8);
	testEasyfind(deque, "Deque", std::numeric_limits<int>::max());
	return (0);
}
