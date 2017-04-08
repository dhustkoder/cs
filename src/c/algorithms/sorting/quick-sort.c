#include <stdio.h>
#include <stdlib.h>
#include "../../common.h"
#include "quick-sort.h"


int main(const int argc, const char* const* const argv)
{
	if (argc < 3) {
		fprintf(stderr, "Usage: %s [list]\n", argv[0]);
		return EXIT_FAILURE;
	}

	const int size = argc - 1;
	int* const arr = make_array_from_strings(argv + 1, size);

	sort_routine(arr, size, sizeof(int), quick_sort, cmp_int_less);

	free(arr);
	return EXIT_SUCCESS;
}

