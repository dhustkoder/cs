#ifndef CS_COMMON_H_
#define CS_COMMON_H_
#include <stdlib.h>
#include "data-structures/ds-generics.h"
#include "algorithms/searching/binary-search.h"
#include "algorithms/sorting/quick-sort.h"
#include "utils.h"


#ifdef DS_VECTOR

#define DSTYPE Vector
#define CREATE_DS(nmemb, size) (create_vector(nmemb, size))
#define DESTROY_DS(ds) (destroy_vector(ds))
#define DS_CADVANCE vector_cadvance
#define DS_ADVANCE vector_advance

#elif defined(DS_LINKED_LIST)

#define DSTYPE LinkedList
#define CREATE_DS(nmemb, size) (create_linked_list(size))
#define DESTROY_DS(ds) (destroy_linked_list(ds))
#define DS_CADVANCE linked_list_cadvance
#define DS_ADVANCE linked_list_advance

#endif


static inline DSTYPE* create_int_ds_from_strings(const char* const* const strs, const int size)
{
	DSTYPE* const ds = CREATE_DS(size, sizeof(int));

	for (int i = 0; i < size; ++i) {
		const int num = strtol(strs[i], NULL, 0);
		push_back(&num, ds);
	}

	return ds;
}


static inline int cmp_int(const void* const a, const void* const b)
{
	return *((const int*)a) - *((const int*)b);
}


static inline void swap_int(void* const a, void* const b)
{
	const int tmp = *((int*)a);
	*((int*)a) = *((int*)b);
	*((int*)b) = tmp;
}


static inline void print_int_data(const ConstIterator begin,
                                  const ConstIterator end,
				  const ConstAdvanceFun advance)
{
	int i = 0;
	for (ConstIterator it = begin; it.ptr != end.ptr; it = advance(it, 1))
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
	DSTYPE* const ds = create_int_ds_from_strings(argv + 1, size);

#ifdef CSDEBUG
	printf("UNSORTED:\n");
	print_int_data(cbegin(ds), cend(ds), DS_CADVANCE);
#endif

	sortfun(begin(ds), end(ds), swap_int, cmp_int, DS_ADVANCE);
	
#ifdef CSDEBUG
	printf("SORTED:\n");
	print_int_data(cbegin(ds), cend(ds), DS_CADVANCE);
#endif
	
	DESTROY_DS(ds);
	return EXIT_SUCCESS;
}


static inline int search_test(const int argc,
                              const char* const * const argv,
                              const SearchFun searchfun)
{
	if (argc < 4) {
		fprintf(stderr, "Usage: %s [list] [target]\n", argv[0]);
		return EXIT_FAILURE;
	}

	const int size = argc - 2;
	const int target = strtol(argv[argc - 1], NULL, 0);
	DSTYPE* const ds = create_int_ds_from_strings(argv + 1, size);

#ifdef CSDEBUG
	printf("ARRAY:\n");
	print_int_data(cbegin(ds), cend(ds), DS_CADVANCE);
#endif

	const ConstIterator found = searchfun(cbegin(ds), cend(ds), &target, cmp_int, DS_CADVANCE);

	if (found.ptr != cend(ds).ptr)
		printf("%d FOUND AT INDEX %d\n", *((const int*)found.ptr), found.index);
	else
		printf("%d NOT FOUND\n", target);

	DESTROY_DS(ds);
	return EXIT_SUCCESS;
}



#endif

