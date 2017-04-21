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
			Iterator it1 = end;
			advance(&it1, -j);
			Iterator it2 = it1;
			advance(&it2, -1);

			if (cmp(it1.ptr, it2.ptr) >= 0)
				break;

			swap(it1.ptr, it2.ptr);
		}
	}
}


#endif

