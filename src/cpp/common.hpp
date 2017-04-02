#ifndef CS_COMMON_HPP_
#define CS_COMMON_HPP_
#include <cstring>
#include <vector>
#include <iostream>

inline std::vector<int> make_int_vector_from_strings(const char* const * strs, const int size)
{
	std::vector<int> r;
	r.reserve(size);

	for (int i = 0; i < size; ++i)
		r.push_back(static_cast<int>(std::strtol(strs[i], NULL, 0)));

	return r;
}


template<class T>
void print_data(const T& data)
{
	for (const auto& x : data)
		std::cout << x << '\n';
}


#endif
