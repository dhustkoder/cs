#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "common.h"
#include "binary-search.h"
#include "algorithms/sorting/quick-sort.h"

static bool compare(const void* const lhs, const void* const rhs)
{
	return (*(int*)lhs) < (*(int*)rhs);
}	


int main(const int argc, const char* const * const argv)
{
	if (argc < 3) {
		fprintf(stderr, "Usage: %s [list] [target]\n", argv[0]);
		return EXIT_FAILURE;
	}

	const int target = (int) strtol(argv[argc - 1], NULL, 0);
	const int size = argc - 2;
	int* const array = make_array_from_strings(&argv[1], size);
	quick_sort(array, size, sizeof(int), compare);
	print_array(array, size);

	const int* const addr = binary_search(array, size, sizeof(int), &target, compare);

	if (addr)
		printf("FOUND %d AT INDEX %d\n", target, (int) (addr - array));
	else
		printf("NOT FOUND!\n");

	free(array);
	return EXIT_SUCCESS;
}



