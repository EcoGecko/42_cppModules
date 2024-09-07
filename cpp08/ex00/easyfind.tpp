

#include "easyfind.hpp"

template<typename T>
int	easyfind(T &container, int value) {
	typename T::iterator pos;

	pos = std::find(container.begin(),  container.end(), value);
	if (pos == container.end()) {
		return -1;
	}
	return (std::distance(container.begin(), pos));
}
