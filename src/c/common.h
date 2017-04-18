#ifndef CS_COMMON_H_
#define CS_COMMON_H_
#include <stdlib.h>
#include "data-structures/ds-generics.h"

#define UNUSED(x) ((void)x)


typedef int(*CmpFun)(const void*, const void*);
typedef const void*(*ConstSearchFun)(const void*, int, int, const void*, CmpFun);
typedef const void*(*SearchFun)(void*, int, int, const void*, CmpFun);
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


static inline void print_int_array(const int* const a, const int size)
{
	for (int i = 0; i < size; ++i)
		printf("[%d] = %d\n", i, a[i]);
}

static inline void print_str_array(const char* const * a, const int size)
{
	for (int i = 0; i < size; ++i)
		printf("[%d] = %s\n", i, a[i]);
}


#define print_array(array, size)                         \
        _Generic((array),                                \
        const int*: print_int_array,                     \
        int*: print_int_array,                           \
        const char**: print_str_array,                   \
        char**: print_str_array)(array, size)




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
	print_array((int*)vec->data, size);
#endif

	sortfun((int*)vec->data, size, sizeof(int), cmp_int);
	
#ifdef CSDEBUG
	printf("SORTED:\n");
	print_array((int*)vec->data, size);
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

	const int* const found = searchfun((int*)vec->data, size, sizeof(int), &target, cmp_int);

#ifdef CSDEBUG
	printf("ARRAY:\n");
	print_array((int*)vec->data, size);
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

