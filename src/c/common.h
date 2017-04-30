#ifndef CS_COMMON_H_
#define CS_COMMON_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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


#ifdef DS_TYPE_INT

#define CREATE_DS_FROM_STRINGS(strs, size) (create_int_ds_from_strings(strs, size))
#define CMP_FUN cmp_int
#define SWAP_FUN swap_int
#define PRINT_DATA print_int_data

#elif defined(DS_TYPE_STR)

#define CREATE_DS_FROM_STRINGS(strs, size) (create_str_ds_from_strings(strs, size))
#define CMP_FUN cmp_str
#define SWAP_FUN swap_str
#define PRINT_DATA print_str_data

#endif


static inline DSTYPE* create_int_ds_from_strings(const char** const strs, const int size)
{
	DSTYPE* const ds = CREATE_DS(size, sizeof(int));

	for (int i = 0; i < size; ++i) {
		const int num = strtol(strs[i], NULL, 0);
		push_back(&num, ds);
	}

	return ds;
}


static inline DSTYPE* create_str_ds_from_strings(const char** const strs, const int size)
{
	DSTYPE* const ds = CREATE_DS(size, sizeof(char*));
	push_back_array(strs, size, ds);
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


static inline int cmp_str(const void* const str_a, const void* const str_b)
{
	const char* a = *((char**)str_a);
	const char* b = *((char**)str_b);
	int acnt, bcnt;
	for (acnt = 0; *a++ != '\0'; ++acnt) {}
	for (bcnt = 0; *b++ != '\0'; ++bcnt) {}
	return acnt - bcnt;
}


static inline void swap_str(void* const str_a, void* const str_b)
{
	char* const tmp = *((char**)str_a);
	*((char**)str_a) = *((char**)str_b);
	*((char**)str_b) = tmp;
}


static inline void print_int_data(const ConstIterator begin,
                                  const ConstIterator end,
				  const ConstAdvanceFun advance)
{
	int i = 0;
	for (ConstIterator it = begin; it.ptr != end.ptr; it = advance(it, 1))
		printf("[%d] = %d\n", i++, *((const int*)it.ptr));
}


static inline void print_str_data(const ConstIterator begin,
                                  const ConstIterator end,
				  const ConstAdvanceFun advance)
{
	int i = 0;
	for (ConstIterator it = begin; it.ptr != end.ptr; it = advance(it, 1))
		printf("[%d] = %s\n", i++, *((const char* const *)it.ptr));
}


static inline int sort_test(const int argc,
                            const char** const argv,
                            const SortFun sortfun)
{
	if (argc < 3) {
		fprintf(stderr, "Usage: %s [list]\n", argv[0]);
		return EXIT_FAILURE;
	}

	const int size = argc - 1;
	DSTYPE* const ds = CREATE_DS_FROM_STRINGS(argv + 1, size);

#ifdef CSDEBUG
	printf("UNSORTED:\n");
	PRINT_DATA(cbegin(ds), cend(ds), DS_CADVANCE);
#endif

	sortfun(begin(ds), end(ds), SWAP_FUN, CMP_FUN, DS_ADVANCE);
	
#ifdef CSDEBUG
	printf("SORTED:\n");
	PRINT_DATA(cbegin(ds), cend(ds), DS_CADVANCE);
#endif
	
	DESTROY_DS(ds);
	return EXIT_SUCCESS;
}


static inline int search_test(const int argc,
                              const char** const argv,
                              const SearchFun searchfun)
{
	if (argc < 4) {
		fprintf(stderr, "Usage: %s [list] [target]\n", argv[0]);
		return EXIT_FAILURE;
	}

	const int size = argc - 2;

#ifdef DS_TYPE_INT
#define TYPE int
#define PFMT "%d"
	const TYPE target = strtol(argv[argc - 1], NULL, 0);
#elif defined(DS_TYPE_STR)
#define TYPE char* const
#define PFMT "%s"
	const TYPE target = argv[argc - 1];
#endif

	DSTYPE* const ds = CREATE_DS_FROM_STRINGS(argv + 1, size);

#ifdef CSDEBUG
	printf("ARRAY:\n");
	PRINT_DATA(cbegin(ds), cend(ds), DS_CADVANCE);
#endif

	const ConstIterator found = searchfun(cbegin(ds), cend(ds), &target, CMP_FUN, DS_CADVANCE);


	if (found.ptr != cend(ds).ptr)
		printf("%d FOUND AT INDEX " PFMT "\n", *((TYPE*)found.ptr), found.index);
	else
		printf(PFMT " NOT FOUND\n", target);

	DESTROY_DS(ds);
	return EXIT_SUCCESS;
}



#endif

