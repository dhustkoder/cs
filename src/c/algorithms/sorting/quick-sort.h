#ifndef CS_ALGORITHMS_QUICK_SORT_H_
#define CS_ALGORITHMS_QUICK_SORT_H_
#include <stdbool.h>
#include <string.h>


static inline int quick_sort_part(char* const arr,
                                  const int beg,
				  const int end,
				  const int membsize,
				  bool(*compare)(const void*, const void*))
{
	int l = beg + membsize;
	int r = end;
	void* const p = &arr[beg];
	char tmp[membsize];

	for (;;) {
		while (l < r && compare(&arr[l], p))
			l += membsize;
		while (r >= l && compare(p, &arr[r]))
			r -= membsize;
		
		if (l >= r)
			break;

		memcpy(tmp, &arr[r], membsize);
		memcpy(&arr[r], &arr[l], membsize);
		memcpy(&arr[l], tmp, membsize);

		r -= membsize;
		l += membsize;
	}

	memcpy(tmp, &arr[r], membsize);
	memcpy(&arr[r], p, membsize);
	memcpy(p, tmp, membsize);
	return r;
}


static inline void quick_sort_rec(char* const arr,
                                  const int beg,
				  const int end,
				  const int membsize,
				  bool(*compare)(const void*, const void*))
{
	if ((end - beg) > 0) {
		const int split = quick_sort_part(arr, beg, end, membsize, compare);
		quick_sort_rec(arr, beg, split - membsize, membsize, compare);
		quick_sort_rec(arr, split + membsize, end, membsize, compare);
	}
}


static inline void quick_sort(void* const arr,
                              const int nmemb,
			      const int size,
			      bool(*compare)(const void*, const void*))
{
	if (nmemb > 1)
		quick_sort_rec(arr, 0, (nmemb * size) - size, size, compare);
}


#endif

