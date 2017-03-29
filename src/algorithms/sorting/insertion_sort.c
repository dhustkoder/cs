#include <stdio.h>
#include <stdlib.h>
#include "common.h"


static void insertion_sort(int* const a, const int size)
{
	for (int i = 1; i < size - 1; ++i) {
		for (int j = i; j > 0 && a[j] < a[j - 1]; --j) {
			const int tmp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = tmp;
		}
	}
}


int main(const int argc, const char* const* const argv)
{
	if (argc < 3) {
		fprintf(stderr, "Usage: %s [list]\n", argv[0]);
		return EXIT_FAILURE;
	}

	const int size = argc - 1;
	int* const arr = make_array_from_strings(argv + 1, size);
	insertion_sort(arr, size);

	for (int i = 0; i < size; ++i)
		printf("[%d] = %d\n", i, arr[i]);

	free(arr);
	return EXIT_SUCCESS;
}

