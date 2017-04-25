#ifndef CS_ALGORITHMS_QUICK_SORT_H_
#define CS_ALGORITHMS_QUICK_SORT_H_
#include "utils.h"


static inline Iterator quick_sort_part(const Iterator begin,
                                       const Iterator end,
				       const SwapFun swap,
				       const CmpFun cmp,
				       const AdvanceFun advance)
{
	Iterator l = advance(begin, 1);
	Iterator r = advance(end, -1);

	void* const p = begin.ptr;

	for (;;) {
		while (l.index < r.index && cmp(l.ptr, p) < 0)
			l = advance(l, 1);
		while (r.index >= l.index && cmp(r.ptr, p) > 0)
			r = advance(r, -1);
		
		if (l.index >= r.index)
			break;

		swap(l.ptr, r.ptr);

		r = advance(r, -1);
		l = advance(l, 1);
	}

	swap(r.ptr, p);
	return r;
}


static inline void quick_sort(const Iterator begin,
                              const Iterator end,
			      const SwapFun swap,
			      const CmpFun cmp,
			      const AdvanceFun advance)
{
	if ((end.index - begin.index) > 1) {
		const Iterator split = quick_sort_part(begin, end, swap, cmp, advance);
		quick_sort(begin, split, swap, cmp, advance);
		quick_sort(advance(split, 1), end, swap, cmp, advance);
	}
}


#endif

