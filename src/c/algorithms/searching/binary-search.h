#ifndef CS_ALGORITHMS_BINARY_SEARCH_H_
#define CS_ALGORITHMS_BINARY_SEARCH_H_
#include "unused.h"

static inline const void* binary_search(const Iterator begin,
                                        const Iterator end,
					const void* const target,
					int(*cmp)(const void*, const void*),
					void(*const next)(Iterator*, int),
					void(*const prev)(Iterator*, int))
{
	UNUSED(prev);
	int min = 0;
	int max = end.index - 1;

	while (min <= max) {
		const int guess = (min + max) / 2;
		Iterator it = begin;
		next(&it, guess);
		const int result = cmp(it.elem, target);
		if (result < 0)
			min = guess + 1;
		else if (result > 0)
			max = guess - 1;
		else
			return it.elem;
	}

	return NULL;
}


#endif

