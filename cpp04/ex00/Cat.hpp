#ifndef CAT_H
#define CAT_H

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal {

private:

public:
    Cat(void);
    Cat(Cat const &obj);

    Cat &operator=(Cat const &obj);

    ~Cat(void);
	void makeSound(void) const;
};

#endif
