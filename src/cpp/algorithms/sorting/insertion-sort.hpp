#ifndef CS_ALGORITHMS_INSERTION_SORT_HPP_
#define CS_ALGORITHMS_INSERTION_SORT_HPP_
#include <utility>


template<class T, class Fn>
void insertion_sort(T* const data, const int size, Fn compare)
{
	T& a = *data;
	for (int i = 1; i < size; ++i) {
		for (int j = i; j > 0 && compare(a[j], a[j - 1]); --j) {
			auto aux = std::move(a[j]);
			a[j] = std::move(a[j - 1]);
			a[j - 1] = std::move(aux);
		}
	}
}







#endif

