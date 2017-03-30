#include <stdio.h>
#include <stdlib.h>
#include "../../common.h"
#include "bubble-sort.h"


static inline bool compare(const void* a, const void* b)
{
	return *((int*)a) < *((int*)b);
}


int main(const int argc, const char* const* const argv)
{
	if (argc < 3) {
		fprintf(stderr, "Usage: %s [list]\n", argv[0]);
		return EXIT_FAILURE;
	}

	const int size = argc - 1;
	int* const arr = make_array_from_strings(argv + 1, size);
	bubble_sort(arr, size, sizeof(int), compare);
	print_array(arr, size);
	free(arr);
	return EXIT_SUCCESS;
}

