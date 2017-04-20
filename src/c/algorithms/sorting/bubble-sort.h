#ifndef CS_ALGORITHMS_BUBBLE_SORT_H_
#define CS_ALGORITHMS_BUBBLE_SORT_H_
#include <string.h>
#include "utils.h"


static inline void bubble_sort(const Iterator begin,
                               const Iterator end,
			       const int size,
			       const CmpFun cmp,
			       const AdvanceFun advance)
{
	unsigned char tmp[size];

	for (Iterator it = begin; it.ptr != end.ptr; advance(&it, 1)) {
		Iterator jend = end;
		advance(&jend, -(1 + it.index));
		for (Iterator j = begin; j.ptr != jend.ptr; advance(&j, 1)) {
			Iterator jnext = j;
			advance(&jnext, 1);
			if (cmp(jnext.ptr, j.ptr) < 0) {
				memcpy(tmp, jnext.ptr, size);
				memcpy(jnext.ptr, j.ptr, size);
				memcpy(j.ptr, tmp, size);
			}
		}
	}
}


#endif
