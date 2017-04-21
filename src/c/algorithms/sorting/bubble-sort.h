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
	UNUSED(swap);
	unsigned char tmp[sizeof(int)];
	for (int i = begin.index; i < end.index; ++i) {
		const int jend = end.index - 1 - i;
		for (int j = begin.index; j < jend; ++j) {
			Iterator it1 = begin;
			advance(&it1, j);
			Iterator it2 = it1;
			advance(&it2, 1);
			if (cmp(it2.ptr, it1.ptr) < 0) {
				memcpy(tmp, it1.ptr, sizeof(int));
				memcpy(it1.ptr, it2.ptr, sizeof(int));
				memcpy(it2.ptr, tmp, sizeof(int));
				//swap(it2.ptr, it1.ptr);
			}
		}
	}
}


#endif
