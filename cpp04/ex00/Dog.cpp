#include "Dog.hpp"

Dog::Dog(void) {

	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
}

Dog::Dog(Dog const &obj) : Animal(obj) {

	std::cout << "Dog copy constructor called" << std::endl;
	*this = obj;
}

Dog &Dog::operator=(Dog const &obj) {

	if (this == &obj) {
		return (*this);
	}
	this->type = obj.type;
	return (*this);
}

Dog::~Dog(void) {

	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const {

	std::cout << "Dog: Barks" << std::endl;
}
