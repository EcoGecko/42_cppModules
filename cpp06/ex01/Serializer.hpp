

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"

typedef unsigned long int	uintptr_t;

class Serializer {
private:
	Serializer(void);
	Serializer(Serializer const &obj);
	Serializer &operator=(Serializer const &obj);

	~Serializer(void);

public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};


#endif
