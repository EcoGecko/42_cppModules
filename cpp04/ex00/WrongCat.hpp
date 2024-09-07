#ifndef WRONGCAT_H
#define WRONGCAT_H

#include "WrongAnimal.hpp"
#include <iostream>
#include <string>

class WrongCat : public WrongAnimal {

private:

public:
	WrongCat(void);
	WrongCat(WrongCat const &obj);

	WrongCat &operator=(WrongCat const &obj);

	~WrongCat(void);

	void	makeSound(void) const;
};

#endif
