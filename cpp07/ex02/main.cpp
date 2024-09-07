


#include "Array.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

template <typename T>
void print(Array<T> &arr, std::string const &str, std::string const &msg) {
	std::cout << msg;
	std::cout << str + " Array size: " << arr.size() << "\n";
	for (size_t i = 0; i < arr.size(); i++)
		std::cout << str + " Array[" << i << "] = " << arr[i] << "\n";
	std::cout << "-------------------------\n";
}

void	test(Array<int> &arr, Array<int> &arrCopy) {
	for (size_t i = 0; i < arr.size(); i++)
		arr[i] = i;

	std::cout << "-------------------------\n";
	print(arr, "int", "");
	print(arrCopy, "int copy", "");
	arrCopy = arr;
	print(arrCopy, "int copy", "After copying numbers to the copy\n");
	arr[1] = 42;
	print(arr, "int", "After setting numbers[1] to 42\n");
	print(arrCopy, "int copy", "After setting numbers[1] to 42\n");
	
	try {
		arr[5] = 5;
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}
}

void	test(Array<std::string> &arr, Array<std::string> &arrCopy) {
	for (size_t i = 0; i < arr.size(); i++)
		arr[i] = "Hello";

	std::cout << "-------------------------\n";
	print(arr, "string", "");
	print(arrCopy, "string copy", "");
	arrCopy = arr;
	print(arrCopy, "String copy", "After copying stringArray to the copy\n");
	arr[1] = "world!";
	arrCopy[1] = "Goodbye";
	print(arr, "string", "After changing stringArray and stringArrayCopy\n");
	print(arrCopy, "int copy", "After setting stringArray[1] to world!\n");

	try {
		arr[3] = "World";
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}
}

int main(void) {
	Array<int>		   numbers(5);
	Array<int>		   numbersCopy;

	test(numbers, numbersCopy);

	Array<std::string> stringArray(3);
	Array<std::string> stringArrayCopy(stringArray);

	test(stringArray, stringArrayCopy);

	return (EXIT_SUCCESS);
}
