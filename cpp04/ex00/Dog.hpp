#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal {

private:

public:
	Dog(void);
	Dog(Dog const &obj);

	Dog &operator=(Dog const &obj);

	~Dog(void);
	void makeSound(void) const;
};

#endif
