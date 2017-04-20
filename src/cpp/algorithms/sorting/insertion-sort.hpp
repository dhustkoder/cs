#ifndef CS_ALGORITHMS_INSERTION_SORT_HPP_
#define CS_ALGORITHMS_INSERTION_SORT_HPP_
#include <utility>
#include <iterator>


template<class Itr, class Fn>
void insertion_sort(const Itr begin, const Itr end, Fn compare)
{

	for (auto i = begin; i != end; i = std::next(i)) {

		for (auto j = i; j != begin; j = std::prev(j)) {
			auto jprev = std::prev(j);
			const auto& f = *j;
			const auto& s = *jprev;

			if (!compare(f, s))
				break;

			auto aux = std::move(*j);
			*j = std::move(*jprev);
			*jprev = std::move(aux);
		}

	}

}







#endif

