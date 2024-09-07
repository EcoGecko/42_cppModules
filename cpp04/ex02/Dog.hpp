#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Dog : public Animal {

private:
	Brain *brain;

public:
	Dog(void);
	Dog(Dog const &obj);

	Dog &operator=(Dog const &obj);

	~Dog(void);
	void makeSound(void) const;
};

#endif
