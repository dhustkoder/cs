#ifndef CS_ALGORITHMS_SEARCHING_LINEAR_SEARCH_H_
#define CS_ALGORITHMS_SEARCHING_LINEAR_SEARCH_H_
#include <stdlib.h>
#include "utils.h"


static inline const void* linear_search(const ConstIterator begin,
                                        const ConstIterator end,
				        const void* const target,
				        const CmpFun cmp,
					const ConstNextFun next,
					const ConstPrevFun prev)
{
	UNUSED(prev);
	for (ConstIterator it = begin; it.elem != end.elem; next(&it, 1))
		if (cmp(target, it.elem) == 0)
			return it.elem;
	return NULL;
}




#endif
