#ifndef CS_ALGORITHMS_INSERTION_SORT_H_
#define CS_ALGORITHMS_INSERTION_SORT_H_
#include <string.h>


static void insertion_sort(void* const array, const int nmemb, const int size, int(*cmp)(const void*, const void*))
{
	if (nmemb < 2)
		return;

	char tmp[size];
	const int bytes = nmemb * size;
	char* const a = (char*) array;

	for (int i = size; i < bytes; i += size) {
		for (int j = i; j > 0 && cmp(&a[j], &a[j - size]) < 0; j -= size) {
			memcpy(tmp, &a[j], size);
			memcpy(&a[j], &a[j - size], size);
			memcpy(&a[j - size], tmp, size);
		}
	}
}


#endif

