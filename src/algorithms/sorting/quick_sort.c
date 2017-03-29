#include <stdio.h>
#include <stdlib.h>
#include "common.h"


static int* quick_sort(int* arr, int size);
static void quick_sort_rec(int* arr, int beg, int end);
static int quick_sort_part(int* arr, int beg, int end);


int main(const int argc, const char* const * const argv)
{
	if (argc < 3) {
		fprintf(stderr, "Usage: %s [list]\n", argv[0]);
		return EXIT_FAILURE;
	}

	const int size = argc - 1;
	int* const array = quick_sort(make_array_from_strings(&argv[1], size), size);

	for (int i = 0; i < size; ++i)
		printf("[%d] = %d\n", i, array[i]);

	free(array);
	return EXIT_SUCCESS;
}


int* quick_sort(int* const arr, const int size)
{
	if (size > 1)
		quick_sort_rec(arr, 0, size - 1);

	return arr;
}


void quick_sort_rec(int* const arr, const int beg, const int end)
{
	if ((end - beg) > 0) {
		const int split = quick_sort_part(arr, beg, end);
		quick_sort_rec(arr, beg, split - 1);
		quick_sort_rec(arr, split + 1, end);
	}
}


int quick_sort_part(int* const arr, const int beg, const int end)
{
	const int p = arr[beg];
	int l = beg + 1;
	int r = end;

	for (;;) {
		while (l < end && arr[l] < p)
			++l;
		while (r >= l && arr[r] > p)
			--r;

		if (l >= r)
			break;

		const int aux = arr[r];
		arr[r] = arr[l];
		arr[l] = aux;

		++l;
		--r;
	}

	const int aux = arr[r];
	arr[r] = p;
	arr[beg] = aux;
	return r;
}

