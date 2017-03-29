#include <stdio.h>
#include <stdlib.h>
#include "common.h"


static const int* binary_search(const int target, const int* const array, const int size)
{
	int min = 0;
	int max = size - 1;
	int guess;

	while (min <= max) {
		guess = (min + max) / 2;
		if (array[guess] < target)
			min = guess + 1;
		else if (array[guess] > target)
			max = guess - 1;
		else
			return &array[guess];
	}

	return NULL;
}


static int compare(const void* const lhs, const void* const rhs)
{
	return (*(int*)lhs) > (*(int*)rhs);
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
	qsort(array, size, sizeof(int), compare);

	for (int i = 0; i < size; ++i)
		printf("[%d] = %d\n", i, array[i]);

	const int* const addr = binary_search(target, array, size);

	if (addr)
		printf("FOUND %d AT INDEX %d\n", target, (int) (addr - array));
	else
		printf("NOT FOUND!\n");

	free(array);
	return EXIT_SUCCESS;
}



