

#include "MutantStack.hpp"

template <typename T, typename C>
MutantStack<T, C>::MutantStack() {
}

template <typename T, typename C>
MutantStack<T, C>::MutantStack(const MutantStack &rhs) {
		*this = rhs;
}

template <typename T, typename C>
MutantStack<T, C> &MutantStack<T, C>::operator=(const MutantStack &rhs) {
	if (this == &rhs) {
		return (*this);
	}
	this->c = rhs.c;
	return (*this);
}

template <typename T, typename C>
MutantStack<T, C>::~MutantStack() {
}

template <typename T, typename C>
typename MutantStack<T, C>::iterator MutantStack<T, C>::begin() {
	return (this->c.begin());
}

template <typename T, typename C>
typename MutantStack<T, C>::iterator MutantStack<T, C>::end() {
	return (this->c.end());
}
