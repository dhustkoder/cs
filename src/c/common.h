#ifndef CS_COMMON_H_
#define CS_COMMON_H_
#include <stdlib.h>
#include "data-structures/ds-generics.h"
#include "algorithms/searching/binary-search.h"
#include "algorithms/sorting/quick-sort.h"
#include "utils.h"


static inline Vector* create_int_vector_from_strings(const char* const* const strs, const int size)
{
	Vector* const v = create_vector(size, sizeof(int));

	for (int i = 0; i < size; ++i) {
		const int num = strtol(strs[i], NULL, 0);
		push_back(&num, v);
	}

	return v;
}


static inline int cmp_int(const void* const a, const void* const b)
{
	return *((const int*)a) - *((const int*)b);
}


static inline void swap_int(void* const a, void* const b)
{
	int tmp = *((int*)a);
	*((int*)a) = *((int*)b);
	*((int*)b) = tmp;
}


static inline void print_int_data(const ConstIterator begin,
                                  const ConstIterator end,
				  const ConstAdvanceFun advance)
{
	int i = 0;
	for (ConstIterator it = begin; it.ptr != end.ptr; advance(&it, 1))
		printf("[%d] = %d\n", i++, *((const int*)it.ptr));
}


static inline int sort_test(const int argc,
                            const char* const * const argv,
                            const SortFun sortfun)
{
	if (argc < 3) {
		fprintf(stderr, "Usage: %s [list]\n", argv[0]);
		return EXIT_FAILURE;
	}

	const int size = argc - 1;
	Vector* const vec = create_int_vector_from_strings(argv + 1, size);

#ifdef CSDEBUG
	printf("UNSORTED:\n");
	print_int_data(cbegin(vec), cend(vec), vector_cadvance);
#endif

	sortfun(begin(vec), end(vec), swap_int, cmp_int, vector_advance);
	
#ifdef CSDEBUG
	printf("SORTED:\n");
	print_int_data(cbegin(vec), cend(vec), vector_cadvance);
#endif
	destroy_vector(vec);
	return EXIT_SUCCESS;
}


static inline int search_test(const int argc,
                              const char* const * argv,
                              const SearchFun searchfun)
{
	if (argc < 4) {
		fprintf(stderr, "Usage: %s [list] [target]\n", argv[0]);
		return EXIT_FAILURE;
	}

	const int size = argc - 2;
	const int target = strtol(argv[argc - 1], NULL, 0);
	Vector* const vec = create_int_vector_from_strings(argv + 1, size);

	if (searchfun == &binary_search)
		quick_sort(begin(vec), end(vec), swap_int, cmp_int, vector_advance);

#ifdef CSDEBUG
	printf("ARRAY:\n");
	print_int_data(cbegin(vec), cend(vec), vector_cadvance);
#endif

	const ConstIterator found = searchfun(cbegin(vec), cend(vec), &target, cmp_int, vector_cadvance);

	if (found.ptr != cend(vec).ptr)
		printf("%d FOUND AT INDEX %d\n", *((const int*)found.ptr), found.index);
	else
		printf("%d NOT FOUND\n", target);

	destroy_vector(vec);
	return EXIT_SUCCESS;
}



#endif

