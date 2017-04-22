#ifndef CS_ALGORITHMS_BUBBLE_SORT_H_
#define CS_ALGORITHMS_BUBBLE_SORT_H_
#include <string.h>
#include "utils.h"


static inline void bubble_sort(const Iterator begin,
                               const Iterator end,
			       const SwapFun swap,
			       const CmpFun cmp,
			       const AdvanceFun advance)
{
	for (int i = begin.index; i < end.index; ++i) {
		const int jend = end.index - 1 - i;
		for (int j = begin.index; j < jend; ++j) {
			const Iterator x = advance(begin, j);
			const Iterator y = advance(x, 1);
			if (cmp(x.ptr, y.ptr) > 0)
				swap(x.ptr, y.ptr);	
		}
	}
}


#endif
