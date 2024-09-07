

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C> {
public:
	MutantStack();
	MutantStack(const MutantStack &rhs);
	MutantStack &operator=(const MutantStack &rhs);
	~MutantStack();

	typedef typename C::iterator iterator;
	iterator begin();
	iterator end();
	};

#include "MutantStack.tpp"

#endif
