#ifndef CS_ALGORITHMS_SEARCHING_LINEAR_SEARCH_H_
#define CS_ALGORITHMS_SEARCHING_LINEAR_SEARCH_H_
#include <stdlib.h>
#include "unused.h"


static inline const void* linear_search(const Iterator begin,
                                        const Iterator end,
				        const void* const target,
				        int(*const cmp)(const void*, const void*),
					void(*const next)(Iterator*, const int),
					void(*const prev)(Iterator*, const int))
{
	UNUSED(prev);
	for (Iterator it = begin; it.elem != end.elem; next(&it, 1))
		if (cmp(target, it.elem) == 0)
			return it.elem;
	return NULL;
}




#endif
