#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "common.h"
#include "binary-search.h"
#include "algorithms/sorting/quick-sort.h"


static inline const void* binary_search_prep(const void* const data,
                                             const int nmemb,
                                             const int size,
                                             const void* const target,
                                             int(* const cmp)(const void*, const void*))
{
	quick_sort((void*)data, nmemb, size, cmp);
	return binary_search(data, nmemb, size, target, cmp);
}


int main(const int argc, const char* const * const argv)
{
	return search_test(argc, argv, binary_search_prep);
}

