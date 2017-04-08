#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "linear-search.h"



int main(int argc, const char** argv)
{
	if (argc < 4) {
		fprintf(stderr, "Usage: %s [list] [target]\n", argv[0]);
		return EXIT_FAILURE;
	}

	const int size = argc - 2;
	const int target = strtol(argv[argc - 1], NULL, 0);
	int* const arr = make_array_from_strings(argv + 1, size);

	search_routine(arr, size, sizeof(int), &target, linear_search, cmp_int_eq);

	free(arr);
	return EXIT_SUCCESS;
}



