#include <stdio.h>
#include <stdlib.h>
#include "../../common.h"
#include "quick-sort.h"


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

	printf("UNSORTED:");
	print_array(arr, size);
	quick_sort(arr, size, sizeof(int), compare);
	printf("SORTED:");
	print_array(arr, size);

	free(arr);
	return EXIT_SUCCESS;
}

