#ifndef CS_ALGORITHMS_BUBBLE_SORT_HPP_
#define CS_ALGORITHMS_BUBBLE_SORT_HPP_
#include <utility>

template<class Itr, class Fn>
void bubble_sort(const Itr begin, const Itr end, Fn compare)
{
	for (Itr i = begin; i < end; ++i) {
		for (Itr j = begin; j < ((end - 1) - (i - begin)); ++j) {
			const auto& f = *(j + 1);
			const auto& s = *j;
			if (compare(f, s)) {
				auto aux = std::move(*(j + 1));
				*(j + 1) = std::move(*j);
				*j = std::move(aux);
			}
		}
	}
}





#endif
