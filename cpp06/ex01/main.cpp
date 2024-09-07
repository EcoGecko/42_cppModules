
#include "Serializer.hpp"
#include <iostream>
#include "Data.hpp"

int main(void) {
	Data data;

	data.data = 42;
	std::cout << "Address of data: " << &data << "\n";
	std::cout << "Data = {data = " << data.data << "}\n\n";

	uintptr_t address = Serializer::serialize(&data);
	std::cout << "Serialized data: " << address << "\n\n";

	Data *copy = Serializer::deserialize(address);
	std::cout << "Deserialized data: " << copy << "\n";
	std::cout << "Copy = {data = " << copy->data << "}\n\n";
	return (0);
}
