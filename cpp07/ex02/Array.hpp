

#ifndef ARRAY_HPP
#define ARRAY_HPP

//#include "Array.tpp"
#include <iostream>

template<typename T>
class Array {
private:
	T *_array;
	unsigned int _size;
public:
	Array(void);
	Array(unsigned int n);
	Array(Array const &obj);
	~Array(void);

	Array &operator=(Array const &obj);
	T &operator[](unsigned int index);
	const T &operator[](unsigned int index) const;

	unsigned int size(void) const;
	class OutOfBoundsException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

#include "Array.tpp"

#endif
