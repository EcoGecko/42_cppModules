#include "Span.hpp"

Span::Span(void) : capacity(0) {
}

Span::Span(unsigned int n) : capacity(n) {
}

Span::Span(Span const &rhs) {
	*this = rhs;
}

Span &Span::operator=(Span const &rhs) {
	if (this == &rhs) {
		return (*this);
	}
	this->capacity = rhs.capacity;
	this->container = rhs.container;
	return (*this);
}

Span::~Span(void) {
}

void Span::addNumber(int n) {
	if (this->container.size() >= this->capacity) {
		throw(Span::NoCapacityException());
	}
	this->container.push_back(n);
}

void Span::fill(int a, int b) {
	if (this->container.size() >= this->capacity) {
		throw(Span::NoCapacityException());
	}
	int max = std::max(a, b);
	int min = std::min(a, b);
	while (this->container.size() < this->capacity) {
		int value = min + std::rand() % (max - min);
		this->addNumber(value);
	}
}

int Span::shortestSpan(void) const {
	if (this->container.size() < 2) {
		throw(Span::NoSpanException());
	}

	std::vector<int> container = this->container;
	std::sort(container.begin(), container.end());

	int	shortestSpan = container[1] - container[0];
	for (size_t i = 2; i < container.size(); i++) {
		if (container[i] - container[i - 1] < shortestSpan) {
			shortestSpan = container[i] - container[i - 1];
		}
	}
	return (shortestSpan);
}

int Span::longestSpan(void) const {
	if (this->container.size() < 2) {
		throw(Span::NoSpanException());
	}

	std::vector<int> container = this->container;
	std::sort(container.begin(), container.end());
	return (container[container.size() - 1] - container[0]);
}

std::vector<int> const &Span::getContainer(void) const {
	return (this->container);
}

std::ostream &operator<<(std::ostream &o, Span const &rhs) {
	std::vector<int> container = rhs.getContainer();

	for (size_t i = 0; i < container.size(); i++) {
		o << BOLD "Span[" << i << "] = " RESET << container[i] << "\n";
	}
	return (o);
}

const char *Span::NoSpanException::what() const throw() {
	return ("Not enough numbers to calculate span");
}

const char *Span::NoCapacityException::what() const throw() {
	return ("No capacity to add more numbers");
}
