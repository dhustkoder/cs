#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "vector.h"
#include "algorithms/sorting/bubble-sort.h"


static bool compare(const void* a, const void* b)
{
	return *((int*)a) < *((int*)b);
}


int main(int argc, const char* const * argv)
{
	if (argc < 3) {
		fprintf(stderr, "Usage: %s [list]\n", argv[0]);
		return EXIT_FAILURE;
	}

	int ret = EXIT_SUCCESS;
	const int size = argc - 1;
	int* const arr = make_array_from_strings(argv + 1, size);

	if (arr == NULL)
		return EXIT_FAILURE;

	Vector* const v = create_vector(size, sizeof(int));

	if (v == NULL) {
		ret = EXIT_FAILURE;
		goto arr_free;
	}

	push_back_array(arr, size, v);

	const int vecsize = v->bidx / v->membsize;
	puts("UNSORTED");
	print_array((int*)v->data, vecsize);
	bubble_sort(v->data, vecsize, v->membsize, compare);
	puts("SORTED");
	print_array((int*)v->data, vecsize);


	destroy_vector(v);
arr_free:
	free(arr);
	return ret;
}

