#ifndef CS_ALGORITHMS_INSERTION_SORT_HPP_
#define CS_ALGORITHMS_INSERTION_SORT_HPP_
#include <utility>


template<class T, class Fn>
void insertion_sort(const T begin, const T end, Fn compare)
{
	for (T i = begin; i < end; ++i) {
		for (T j = i; j > begin; --j) {
			const auto& f = *j;
			const auto& s = *(j - 1);

			if (!compare(f, s))
				break;

			auto aux = std::move(*j);
			*j = std::move(*(j - 1));
			*(j - 1) = std::move(aux);
		}
	}
}







#endif

