#ifndef CS_ALGORITHMS_SELECTION_SORT_H_
#define CS_ALGORITHMS_SELECTION_SORT_H_
#include "data-structures/iterator.h"
#include "utils.h"


static inline void selection_sort(const Iterator begin,
                                  const Iterator end,
				  const SwapFun swap,
				  const CmpFun cmp,
				  const AdvanceFun advance)
{
	for (Iterator it = begin; it.index < end.index; it = advance(it, 1)) {
		Iterator min = it;

		for (Iterator i = advance(min, 1); i.index < end.index; i = advance(i, 1))
			if (cmp(i.ptr, min.ptr) < 0)
				min = i;

		if (min.index != it.index)
			swap(it.ptr, min.ptr);
	}
}



#endif

