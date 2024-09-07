

#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename U>
void iter(T *array, int length, void (*func)(U &)) {
	for (int i = 0; i < length; i++)
		func(array[i]);
}

#endif
