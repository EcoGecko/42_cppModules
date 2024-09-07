

#include "iter.hpp"
#include <iostream>

class TestClass {
public:
	TestClass() : _i(0) {
	}

	TestClass(int i) : _i(i) {
	}

	TestClass(TestClass const &TestClass) {
		*this = TestClass;
	}

	TestClass &operator=(TestClass const &TestClass) {
		this->_i = TestClass._i;
		return *this;
	}

	~TestClass() {
	}

	int getI() const {
		return this->_i;
	}

private:
	int _i;
};

std::ostream &operator<<(std::ostream &o, TestClass const &TestClass) {
	o << TestClass.getI();
	return o;
}

template <typename T>
void print(T &i) {
	std::cout << i << std::endl;
}

int main(void) {
	int			array[] = {65, 66, 67, 68, 69};
	char		arr[] = {'a', 'b', 'c', 'd', 'e'};
	std::string str[] = {"Hello", "World", "!"};
	TestClass	s1[] = {TestClass(10), TestClass(20), TestClass(30),
						TestClass(40), TestClass(50)};

	::iter(array, 5, print<char const>);
	::iter(array, 5, print<int const>);
	::iter(arr, 5, print<char>);
	::iter(str, 3, print<std::string>);
	::iter(s1, 5, print<TestClass const>);
	return 0;
}
