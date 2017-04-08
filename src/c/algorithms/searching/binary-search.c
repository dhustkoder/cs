#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "common.h"
#include "binary-search.h"
#include "algorithms/sorting/quick-sort.h"


int main(const int argc, const char* const * const argv)
{
	if (argc < 3) {
		fprintf(stderr, "Usage: %s [list] [target]\n", argv[0]);
		return EXIT_FAILURE;
	}

	const int target = (int) strtol(argv[argc - 1], NULL, 0);
	const int size = argc - 2;
	int* const array = make_array_from_strings(&argv[1], size);
	quick_sort(array, size, sizeof(int), cmp_int_less);

	search_routine(array, size, sizeof(int), &target, binary_search, cmp_int_less);

	free(array);
	return EXIT_SUCCESS;
}



