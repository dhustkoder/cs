#ifndef CS_ALGORITHMS_BINARY_SEARCH_H_
#define CS_ALGORITHMS_BINARY_SEARCH_H_


static inline const void* binary_search(const void* const array,
                                 const int nmemb,
				 const int size,
				 const void* const target,
				 int(*cmp)(const void*, const void*))
{
	int min = 0;
	int max = nmemb - 1;
	int guess;

	const char* const a = array;

	while (min <= max) {
		guess = (min + max) / 2;
		const int r = cmp(&a[guess * size], target);
		if (r < 0)
			min = guess + 1;
		else if (r > 0)
			max = guess - 1;
		else
			return &a[guess * size];
	}

	return NULL;
}


#endif

