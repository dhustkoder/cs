#ifndef CS_ALGORITHMS_INSERTION_SORT_H_
#define CS_ALGORITHMS_INSERTION_SORT_H_
#include <string.h>
#include <stdbool.h>

static void insertion_sort(void* const array, const int nmemb, const int size, bool(*compare)(const void*, const void*))
{
	char tmp[size];
	const int bytes = nmemb * size;
	char* const a = (char*) array;

	for (int i = size; i < (bytes - size); i += size) {
		for (int j = i; j > 0 && compare(&a[j], &a[j - size]); j -= size) {
			memcpy(tmp, &a[j], size);
			memcpy(&a[j], &a[j - size], size);
			memcpy(&a[j - size], tmp, size);
		}
	}
}


#endif

