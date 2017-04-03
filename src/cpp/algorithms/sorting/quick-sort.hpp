#ifndef CS_ALGORITHMS_QUICK_SORT_HPP_
#define CS_ALGORITHMS_QUICK_SORT_HPP_
#include <utility>


template<class T, class Fn>
T quick_sort_part(const T begin, const T end, Fn compare)
{
	const T p = begin;
	T l = begin + 1;
	T r = end - 1;
	const auto& pval = *p;

	for (;;) {
		while (l < r) {
			const auto& lval = *l;
			if (!compare(lval, pval))
				break;

			++l;
		}

		while (r >= l) {
			const auto& rval = *r;
			if (!compare(pval, rval))
				break;
			--r;
		}

		if (l >= r)
			break;

		auto aux = std::move(*r);
		*r = std::move(*l);
		*l = std::move(aux);

		++l;
		--r;
	}

	auto aux = std::move(*r);
	*r = std::move(*p);
	*p = std::move(aux);
	return r;
}


template<class T, class Fn>
void quick_sort(const T begin, const T end, Fn compare)
{
	if ((end - begin) > 1) {
		const T part = quick_sort_part(begin, end, compare);
		quick_sort(begin, part, compare);
		quick_sort(part + 1, end, compare);
	}
}





#endif

