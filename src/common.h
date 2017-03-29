#ifndef STUDY_ALGORITHMS_COMMON_H_
#define STUDY_ALGORITHMS_COMMON_H_


static inline int* make_array_from_strings(const char* const* const strs, const int size)
{
	int* const res = malloc(sizeof(int) * size);

	for (int i = 0; i < size; ++i)
		res[i] = (int) strtol(strs[i], NULL, 0);

	return res;
}


#endif

