#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "common.h"
#include "binary-search.h"
#include "algorithms/sorting/quick-sort.h"


static inline const void* binary_search_prep(const Iterator begin,
                                             const Iterator end,
					     const void* const target,
                                             const CmpFun cmp,
					     const NextFun next,
					     const PrevFun prev)
{
	quick_sort(begin.elem, end.index, sizeof(int), cmp);
	return binary_search(begin, end, target, cmp, next, prev);
}


int main(const int argc, const char* const * const argv)
{
	return search_test(argc, argv, binary_search_prep);
}

