#ifndef CS_ALGORITHMS_BINARY_SEARCH_H_
#define CS_ALGORITHMS_BINARY_SEARCH_H_
#include "utils.h"


static inline ConstIterator binary_search(const ConstIterator begin,
                                          const ConstIterator end,
					  const void* const target,
					  const CmpFun cmp,
					  const ConstAdvanceFun advance)
{
	int min = 0;
	int max = end.index - 1;

	while (min <= max) {
		const int guess = (min + max) / 2;
		const ConstIterator it = advance(begin, guess);
		const int result = cmp(it.ptr, target);
		if (result < 0)
			min = guess + 1;
		else if (result > 0)
			max = guess - 1;
		else
			return it;
	}

	return end;
}


#endif

