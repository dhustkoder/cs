#include <stdio.h>
#include <stdlib.h>
#include "common.h"


static void bubble_sort(int* const a, const int size)
{
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < (size - i - 1); ++j) {
			if (a[j] > a[j + 1]) {
				const int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
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
	int* const array = make_array_from_strings(&argv[1], size);
	bubble_sort(array, size);

	for (int i = 0; i < size; ++i)
		printf("[%d] = %d\n", i, array[i]);

	free(array);
	return EXIT_SUCCESS;
}

