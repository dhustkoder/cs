#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "linear-search.h"


static bool compare(const void* a, const void* b)
{
	return *((int*)a) == *((int*)b);
}

int main(int argc, const char** argv)
{
	if (argc < 4) {
		fprintf(stderr, "Usage: %s [list] [target]\n", argv[0]);
		return EXIT_FAILURE;
	}

	const int size = argc - 2;
	const int target = strtol(argv[argc - 1], NULL, 0);
	int* const arr = make_array_from_strings(argv + 1, size);

	if (arr == NULL)
		return EXIT_FAILURE;

	const int* const found = linear_search(arr, size, sizeof(int), &target, compare);

	if (found != NULL)
		printf("Found \'%d\' at index %d\n", target, (int)(found - arr));
	else
		printf("\'%d\' not found\n", target);

	free(arr);
	return EXIT_SUCCESS;
}



