#ifndef CS_ALGORITHMS_BUBBLE_SORT_HPP_
#define CS_ALGORITHMS_BUBBLE_SORT_HPP_
#include <utility>
#include <iterator>


template<class Itr, class Fn>
void bubble_sort(const Itr begin, const Itr end, Fn cmp)
{
	for (Itr i = begin; i != end; i = std::next(i)) {

		const Itr jend = std::prev(end, 1 + std::distance(begin, i));

		for (Itr j = begin; j != jend; j = std::next(j)) {

			auto jnext = std::next(j);
			const auto& f = *jnext;
			const auto& s = *j;

			if (cmp(f, s)) {
				auto aux = std::move(*jnext);
				*jnext = std::move(*j);
				*j = std::move(aux);
			}

		}

	}
}





#endif
