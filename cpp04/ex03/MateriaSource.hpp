#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include <string>
#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {

private:
	AMateria *_materias[4];
	int _materiasIndex;

public:
    MateriaSource(void);
	MateriaSource(MateriaSource const &obj);

	MateriaSource &operator=(MateriaSource const &obj);

	~MateriaSource(void);

	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const &type);
};

#endif
