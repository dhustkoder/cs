#ifndef CS_COMMON_H_
#define CS_COMMON_H_


static inline int* make_array_from_strings(const char* const* const strs, const int size)
{
	int* const a = malloc(sizeof(int) * size);

	for (int i = 0; i < size; ++i)
		a[i] = strtol(strs[i], NULL, 0);

	return a;
}


static inline void print_array(const int* const a, const int size)
{
	for (int i = 0; i < size; ++i)
		printf("[%d] = %d\n", i, a[i]);
}

#endif

