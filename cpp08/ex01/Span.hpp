#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#define BOLD "\033[1m"
#define RESET "\033[0m"
#define RED "\033[31m"

class Span {
public:
	Span(void);
	Span(unsigned int capacity);
	Span(Span const &rhs);
	Span &operator=(Span const &rhs);

	~Span(void);

	// Member functions
	void addNumber(int n);
	void fill(int a, int b);
	int	 shortestSpan(void) const;
	int	 longestSpan(void) const;

	// Getters
	std::vector<int> const &getContainer(void) const;

	// Exceptions
	class NoSpanException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class NoCapacityException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

private:
	unsigned int	 capacity;
	std::vector<int> container;
};

std::ostream &operator<<(std::ostream &o, Span const &rhs);

#endif
