#ifndef CS_ALGORITHMS_BUBBLE_SORT_H_
#define CS_ALGORITHMS_BUBBLE_SORT_H_
#include <string.h>


static inline void bubble_sort(void* const array, const int nmemb, const int size, int(*cmp)(const void*, const void*))
{
	if (nmemb < 2)
		return;

	char tmp[size];
	char* const a = (char*) array;
	const int bytes = nmemb * size;

	for (int i = 0; i < bytes; i += size) {
		const int end = (bytes - size) - i;
		for (int j = 0; j < end; j += size) {
			if (cmp(&a[j + size], &a[j]) < 0) {
				memcpy(tmp, &a[j + size], size);
				memcpy(&a[j + size], &a[j], size);
				memcpy(&a[j], tmp, size);
			}
		}
	}
}


#endif
