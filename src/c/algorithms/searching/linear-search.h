#ifndef CS_ALGORITHMS_SEARCHING_LINEAR_SEARCH_H_
#define CS_ALGORITHMS_SEARCHING_LINEAR_SEARCH_H_
#include <stdlib.h>


static inline const void* linear_search(const void* const data,
                                  const int nmemb,
				  const int size,
				  const void* value,
				  int(*cmp)(const void*, const void*))
{
	char* const d = (char*) data;
	int limit = nmemb * size;

	for (int i = 0; i < limit; i += size)
		if (cmp(value, &d[i]) == 0)
			return &d[i];

	return NULL;
}




#endif
