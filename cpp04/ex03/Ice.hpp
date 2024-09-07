#ifndef ICE_H
#define ICE_H

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria {

private:

public:
    Ice(void);
	Ice(Ice const &obj);

	Ice &operator=(Ice const &obj);

	~Ice(void);

	AMateria *clone(void) const;
	void	  use(ICharacter &target);
};

#endif
