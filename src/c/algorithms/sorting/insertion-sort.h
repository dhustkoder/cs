#ifndef CS_ALGORITHMS_INSERTION_SORT_H_
#define CS_ALGORITHMS_INSERTION_SORT_H_
#include <string.h>
#include "utils.h"


static inline void insertion_sort(const Iterator begin,
                                  const Iterator end,
				  const int size,
				  const CmpFun cmp,
				  const AdvanceFun advance)
{
	unsigned char tmp[size];

	for (Iterator it = begin; it.ptr != end.ptr; advance(&it, 1)) {
		for (Iterator j = it; j.ptr != begin.ptr; advance(&j, -1)) {
			Iterator jprev = j;
			advance(&jprev, -1);

			if (cmp(j.ptr, jprev.ptr) >= 0)
				break;

			memcpy(tmp, j.ptr, size);
			memcpy(j.ptr, jprev.ptr, size);
			memcpy(jprev.ptr, tmp, size);
		}
	}
}


#endif

