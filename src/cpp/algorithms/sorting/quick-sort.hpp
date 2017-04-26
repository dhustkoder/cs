#ifndef CS_ALGORITHMS_QUICK_SORT_HPP_
#define CS_ALGORITHMS_QUICK_SORT_HPP_
#include <utility>
#include <iterator>


template<class Itr, class Fn>
Itr quick_sort_part(const Itr begin, const Itr end, Fn cmp)
{
	const auto p = begin;
	auto l = std::next(begin);
	auto r = std::prev(end);
	const auto& pval = *p;

	for (;;) {
		while (l < r) {
			const auto& lval = *l;
			if (!cmp(lval, pval))
				break;
			l = std::next(l);
		}

		while (r >= l) {
			const auto& rval = *r;
			if (!cmp(pval, rval))
				break;
			r = std::prev(r);
		}

		if (l >= r)
			break;

		auto aux = std::move(*r);
		*r = std::move(*l);
		*l = std::move(aux);

		l = std::next(l);
		r = std::prev(r);
	}

	auto aux = std::move(*r);
	*r = std::move(*p);
	*p = std::move(aux);
	return r;
}


template<class Itr, class Fn>
void quick_sort(const Itr begin, const Itr end, Fn compare)
{
	if ((end - begin) > 1) {
		const auto part = quick_sort_part(begin, end, compare);
		quick_sort(begin, part, compare);
		quick_sort(std::next(part), end, compare);
	}
}





#endif

