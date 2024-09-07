#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class Cat : public Animal {

private:
	Brain *brain;

public:
	Cat(void);
	Cat(Cat const &obj);

	Cat &operator=(Cat const &obj);

	~Cat(void);
	void makeSound(void) const;
	Brain *getBrain(void) const;
};

#endif
