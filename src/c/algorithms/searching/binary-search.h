#ifndef CS_ALGORITHMS_BINARY_SEARCH_H_
#define CS_ALGORITHMS_BINARY_SEARCH_H_

static const void* binary_search(const void* const array,
                                 const int nmemb,
				 const int size,
				 const void* const target,
				 bool(*compare)(const void*, const void*))
{
	int min = 0;
	int max = nmemb - 1;
	int guess;

	const char* const a = array;

	while (min <= max) {
		guess = (min + max) / 2;

		if (compare(&a[guess * size], target))
			min = guess + 1;
		else if (compare(target, &a[guess * size]))
			max = guess - 1;
		else
			return &a[guess * size];
	}

	return NULL;
}


#endif

