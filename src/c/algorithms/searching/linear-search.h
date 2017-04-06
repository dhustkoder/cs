#ifndef CS_ALGORITHMS_SEARCHING_LINEAR_SEARCH_H_
#define CS_ALGORITHMS_SEARCHING_LINEAR_SEARCH_H_
#include <stdlib.h>
#include <stdbool.h>

static inline void* linear_search(void* const data,
                                  const int nmemb,
				  const int size,
				  const void* value,
				  bool(*compare)(const void*, const void*))
{
	char* const d = (char*) data;
	int limit = nmemb * size;

	for (int i = 0; i < limit; i += size)
		if (compare(value, &d[i]))
			return &d[i];

	return NULL;
}




#endif
