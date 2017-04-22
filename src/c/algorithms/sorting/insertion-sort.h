#ifndef CS_ALGORITHMS_INSERTION_SORT_H_
#define CS_ALGORITHMS_INSERTION_SORT_H_
#include <string.h>
#include "utils.h"


static inline void insertion_sort(const Iterator begin,
                                  const Iterator end,
				  const SwapFun swap,
				  const CmpFun cmp,
				  const AdvanceFun advance)
{
	for (int i = begin.index; i < end.index; ++i) {
		for (int j = i; j > begin.index; --j) {
			const Iterator x = advance(end, -j);
			const Iterator y = advance(x, -1);
			if (cmp(x.ptr, y.ptr) >= 0)
				break;
			swap(x.ptr, y.ptr);
		}
	}
}


#endif

