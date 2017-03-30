#include <stdio.h>
#include "vector.h"


int main(void)
{
	const int a[] = { 3, 6, 9, 2, 5, 8, 1, 4, 7 };
	const int size = sizeof(a) / sizeof(a[0]);

	Vector* const v = create_vector(size, sizeof(int));
	push_back_array(a, size, v);

	for (int i = 0; i < size; ++i)
		printf("[%d] = %d\n", i, ((int*)v->data)[i]);
}
