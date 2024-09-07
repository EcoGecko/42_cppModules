

#include "Array.hpp"

template<typename T>
Array<T>::Array(void) : _size(0) {
	this->_array = new T[0];
}

template<typename T>
Array<T>::Array(unsigned int n) : _size(n) {
	this->_array = new T[n];
	for (unsigned int i = 0; i < n; ++i) {
		this->_array[i] = T();
	}
}

template<typename T>
Array<T>::Array(Array const &obj) {
	this->_array = NULL;
	*this = obj;
}

template<typename T>
Array<T>::~Array(void) {
	delete[] this->_array;
}

template<typename T>
Array<T> &Array<T>::operator=(Array<T> const &obj) {
	if (this == &obj) {
		return (*this);
	}
	if (this->_array) {
		delete[] this->_array;
	}
	this->_size  = obj._size;
	this->_array = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; ++i) {
		this->_array[i] = obj._array[i];
	}
	return (*this);
}

template<typename T>
T	&Array<T>::operator[](unsigned int index) {
	if (index >= this->size()) {
		throw Array<T>::OutOfBoundsException();
	}
	return (this->_array[index]);
}

template<typename T>
const T	&Array<T>::operator[](unsigned int index) const {
	if (index >= this->size()) {
		throw Array<T>::OutOfBoundsException();
	}
	return (this->_array[index]);
}

template<typename T>
unsigned int	Array<T>::size(void) const {
	return (this->_size);
}

template<typename T>
const char	*Array<T>::OutOfBoundsException::what() const throw() {
	return ("Index out of bounds");
}
