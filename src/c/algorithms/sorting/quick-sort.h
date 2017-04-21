#ifndef CS_ALGORITHMS_QUICK_SORT_H_
#define CS_ALGORITHMS_QUICK_SORT_H_
#include <string.h>


static inline Iterator quick_sort_part(const Iterator begin,
                                       const Iterator end,
				       const SwapFun swap,
				       const CmpFun cmp,
				       const AdvanceFun advance)
{
	Iterator l = begin;
	advance(&l, 1);
	Iterator r = end;
	advance(&r, -1);

	void* const p = begin.ptr;

	for (;;) {
		while (l.index < r.index && cmp(l.ptr, p) < 0)
			advance(&l, 1);
		while (r.index >= l.index && cmp(r.ptr, p) > 0)
			advance(&r, -1);
		
		if (l.index >= r.index)
			break;

		swap(l.ptr, r.ptr);

		advance(&r, -1);
		advance(&l, 1);
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
		Iterator split = quick_sort_part(begin, end, swap, cmp, advance);
		quick_sort(begin, split, swap, cmp, advance);
		advance(&split, 1);
		quick_sort(split, end, swap, cmp, advance);
	}
}


#endif

