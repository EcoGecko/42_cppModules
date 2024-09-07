#include "Dog.hpp"

Dog::Dog(void) {

	std::cout << "Dog default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(Dog const &obj) : Animal(obj) {

	std::cout << "Dog copy constructor called" << std::endl;
	*this = obj;
}

Dog &Dog::operator=(Dog const &obj) {

	std::cout << "Dog assigment operator called" << std::endl;
	if (this == &obj) {
		return (*this);
	}
	delete this->brain;
	this->brain = new Brain(*obj.brain);
	this->type = obj.type;
	return (*this);
}

Dog::~Dog(void) {

	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

void Dog::makeSound(void) const {

	std::cout << "Dog: Barks" << std::endl;
}
