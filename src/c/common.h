#ifndef CS_COMMON_H_
#define CS_COMMON_H_
#include <stdlib.h>
#include "data-structures/ds-generics.h"


typedef int(*CmpFun)(const void*, const void*);
typedef void(*NextFun)(Iterator*, int);
typedef void(*PrevFun)(Iterator*, int);
typedef const void*(*ConstSearchFun)(const void*, int, int, const void*, CmpFun);
typedef const void*(*SearchFun)(Iterator, Iterator, const void*, CmpFun, NextFun, PrevFun);
typedef void(*SortFun)(void*, int, int, CmpFun);


static inline Vector* create_int_vector_from_strings(const char* const* const strs, const int size)
{
	Vector* const v = create_vector(size, sizeof(int));

	for (int i = 0; i < size; ++i) {
		const int num = strtol(strs[i], NULL, 0);
		push_back(&num, v);
	}

	return v;
}


static inline int cmp_int(const void* a, const void* b)
{
	return *((int*)a) - *((int*)b);
}


static inline void print_int_data(const Iterator begin,
                                  const Iterator end,
				  void(*const next)(Iterator*, const int))
{
	int i = 0;
	for (Iterator it = begin; it.elem != end.elem; next(&it, 1))
		printf("[%d] = %d\n", i++, *((int*)it.elem));
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
	print_int_data(begin(vec), end(vec), vector_next);
#endif

	sortfun((int*)vec->data, size, sizeof(int), cmp_int);
	
#ifdef CSDEBUG
	printf("SORTED:\n");
	print_int_data(begin(vec), end(vec), vector_next);
#endif
	// escape memory to avoid optimization in release mode
	printf("%d\n", ((int*)vec->data)[size - 1]);
	destroy_vector(vec);
	return EXIT_SUCCESS;
}


static inline int search_test_impl(const int argc,
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

	const int* const found = searchfun(begin(vec), end(vec), &target, cmp_int, vector_next, vector_prev);

#ifdef CSDEBUG
	printf("ARRAY:\n");
	print_int_data(begin(vec), end(vec), vector_next);
#endif

	if (found != NULL) {
		const int index = (int) (found - ((int*)vec->data));
		printf("%d FOUND AT INDEX %d\n", target, index);
	} else {
		printf("%d NOT FOUND\n", target);
	}

	destroy_vector(vec);
	return EXIT_SUCCESS;
}


#define search_test(argc, argv, searchfun)                            \
	_Generic((searchfun),                                         \
	ConstSearchFun: search_test_impl,                             \
	SearchFun: search_test_impl)(argc, argv, (SearchFun)searchfun)



#endif

