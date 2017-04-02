#ifndef CS_ALGORITHMS_BUBBLE_SORT_HPP_
#define CS_ALGORITHMS_BUBBLE_SORT_HPP_
#include <utility>

template<class T, class Fn>
void bubble_sort(T* const data, const int size, Fn compare)
{
	if (size < 2)
		return;

	T& a = *data;

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < (size - 1) - i; ++j) {
			const auto& f = a[j + 1];
			const auto& s = a[j];
			if (compare(f, s)) {
				auto aux = std::move(a[j]);
				a[j] = std::move(a[j + 1]);
				a[j + 1] = std::move(aux);
			}
		}
	}
}





#endif
