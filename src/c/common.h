#ifndef CS_COMMON_H_
#define CS_COMMON_H_
#include <stdlib.h>
#include <stdbool.h>


#define UNUSED(x) ((void)x)


static inline int* make_array_from_strings(const char* const* const strs, const int size)
{
	int* const a = malloc(sizeof(int) * size);

	if (a == NULL) {
		fprintf(stderr, "Couldn't allocate memory");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < size; ++i)
		a[i] = strtol(strs[i], NULL, 0);

	return a;
}


static inline bool cmp_int_less(const void* a, const void* b)
{
	return *((int*)a) < *((int*)b);
}


static inline bool cmp_int_greater(const void* a, const void* b)
{
	return *((int*)a) > *((int*)b);
}


static inline bool cmp_int_eq(const void* a, const void* b)
{
	return *((int*)a) == *((int*)b);
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


#ifdef CSDEBUG

#define print_array(array, size)                                  \
	_Generic((array),                                         \
	         const int*: print_int_array,                     \
	         int*: print_int_array,                           \
	         const char**: print_str_array,                   \
	         char**: print_str_array)(array, size) 

#else
	         
// do nothing
#define print_array(...)

#endif


static inline void sort_routine(void* const data, const int nmemb, const int size,
                                void(*sortfun)(void*, int, int, bool(*)(const void*, const void*)),
                                bool(*compare)(const void*, const void*))
{

#ifdef CSDEBUG
	printf("UNSORTED:\n");
	print_array((int*)data, nmemb);
	sortfun(data, nmemb, size, compare);
	printf("SORTED:\n");
	print_array((int*)data, nmemb);
#else
	sortfun(data, nmemb, size, compare);
#endif

}


static inline void search_routine(const void* const data, const int nmemb, const int size, const void* const target,
                                  const void*(*searchfun)(const void*, int, int, const void*, bool(*)(const void*, const void*)),
                                  bool(*compare)(const void*, const void*))
{
#ifdef CSDEBUG
	printf("ARRAY:\n");
	print_array((int*)data, nmemb);
#endif

	const void* found = searchfun(data, nmemb, size, target, compare);

	if (found != NULL)
		printf("FOUND AT INDEX %d\n", (int)(((char*)found - (char*)data) / size));
	else
		printf("NOT FOUND\n");
}



#endif

