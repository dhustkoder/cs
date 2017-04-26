#ifndef CS_ALGORITHMS_SELECTION_SORT_HPP_
#define CS_ALGORITHMS_SELECTION_SORT_HPP_
#include <utility>
#include <iterator>


template<class Itr, class Fn>
void selection_sort(const Itr begin, const Itr end, const Fn cmp)
{
	for (Itr itr = begin; itr != end; itr = std::next(itr, 1)) {
		Itr min = itr;

		for (Itr f = std::next(min, 1); f != end; f = std::next(f, 1)) {
			const auto& x = *f;
			const auto& y = *min;
			if (cmp(x, y))
				min = f;
		}

		if (min != itr) {
			auto tmp = std::move(*min);
			*min = std::move(*itr);
			*itr = std::move(tmp);
		}
	}
}


#endif

