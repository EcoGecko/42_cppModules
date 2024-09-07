#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : _materiasIndex(0) {

	for (int i = 0; i < 4; i++) {
		this->_materias[i] = NULL;
	}

}

MateriaSource::MateriaSource(MateriaSource const &obj) {

	*this = obj;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &obj) {

	if (this == &obj) {
		return (*this);
	}
	for (int i = 0; i < 4; i++) {
		delete this->_materias[i];
		this->_materias[i] = obj._materias[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource(void) {

	for (int i = 0; i < 4; i++) {
		delete this->_materias[i];
	}
}

void MateriaSource::learnMateria(AMateria *m) {

	if (this->_materiasIndex < 4) {
		this->_materias[this->_materiasIndex] = m;
		this->_materiasIndex++;
	}
	else {
		std::cout << "MateriaSource is full" << std::endl;
	}
}

AMateria* MateriaSource::createMateria(std::string const &type) {

	for (int i = 0; i < this->_materiasIndex; i++) {
		if (this->_materias[i]->getType() == type) {
			return (this->_materias[i]->clone());
		}
	}
	return (NULL);
}
