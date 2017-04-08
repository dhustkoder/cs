#ifndef CS_ALGORITHMS_QUICK_SORT_H_
#define CS_ALGORITHMS_QUICK_SORT_H_
#include <string.h>


static inline int quick_sort_part(char* const arr,
                                  const int beg,
				  const int end,
				  const int membsize,
				  int(*cmp)(const void*, const void*))
{
	int l = beg + membsize;
	int r = end;
	void* const p = &arr[beg];
	char tmp[membsize];

	for (;;) {
		while (l < r && cmp(&arr[l], p) < 0)
			l += membsize;
		while (r >= l && cmp(&arr[r], p) > 0)
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
				  int(*cmp)(const void*, const void*))
{
	if ((end - beg) > 0) {
		const int split = quick_sort_part(arr, beg, end, membsize, cmp);
		quick_sort_rec(arr, beg, split - membsize, membsize, cmp);
		quick_sort_rec(arr, split + membsize, end, membsize, cmp);
	}
}


static inline void quick_sort(void* const arr,
                              const int nmemb,
			      const int size,
			      int(*cmp)(const void*, const void*))
{
	if (nmemb > 1)
		quick_sort_rec(arr, 0, (nmemb * size) - size, size, cmp);
}


#endif

