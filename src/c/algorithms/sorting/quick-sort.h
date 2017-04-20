#ifndef CS_ALGORITHMS_QUICK_SORT_H_
#define CS_ALGORITHMS_QUICK_SORT_H_
#include <string.h>


static inline Iterator quick_sort_part(const Iterator begin,
                                       const Iterator end,
				       const int size,
				       const CmpFun cmp,
				       const AdvanceFun advance)
{
	Iterator l = begin;
	advance(&l, 1);
	Iterator r = end;
	advance(&r, -1);

	void* const p = begin.ptr;
	unsigned char tmp[size];

	for (;;) {
		while (l.index < r.index && cmp(l.ptr, p) < 0)
			advance(&l, 1);
		while (r.index >= l.index && cmp(r.ptr, p) > 0)
			advance(&r, -1);
		
		if (l.index >= r.index)
			break;

		memcpy(tmp, r.ptr, size);
		memcpy(r.ptr, l.ptr, size);
		memcpy(l.ptr, tmp, size);

		advance(&r, -1);
		advance(&l, 1);
	}

	memcpy(tmp, r.ptr, size);
	memcpy(r.ptr, p, size);
	memcpy(p, tmp, size);
	return r;
}


static inline void quick_sort(const Iterator begin,
                              const Iterator end,
			      const int size,
			      const CmpFun cmp,
			      const AdvanceFun advance)
{
	if ((end.index - begin.index) > 1) {
		Iterator split = quick_sort_part(begin, end, size, cmp, advance);
		quick_sort(begin, split, size, cmp, advance);
		advance(&split, 1);
		quick_sort(split, end, size, cmp, advance);
	}
}


#endif

