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
	const int limit = static_cast<int>(data.size());
	for (int i = 0; i < limit; ++i)
		std::cout << '[' << i << ']' << " = " << data[i] << '\n';
}


template<class SortFun>
int sort_test(const int argc, const char* const * argv)
{
	if (argc < 3) {
		std::cerr << "Usage: " << argv[0] << " [list]\n";
		return EXIT_FAILURE;
	}

	std::vector<int> v = make_int_vector_from_strings(argv + 1, argc - 1);

#ifdef CSDEBUG
	std::cout << "UNSORTED:\n";
	print_data(v);
#endif

	SortFun()(v.begin(), v.end(), [](int a, int b) { return a < b; });

	
#ifdef CSDEBUG
	std::cout << "SORTED:\n";
	print_data(v);
#endif
	// espace memory to avoid optimization in release mode
	std::cout << v.back() << '\n';
	return EXIT_SUCCESS;
}


template<class SearchFun>
int search_test(const int argc, const char* const * argv)
{
	if (argc < 4) {
		std::cerr << "Usage: " << argv[0] << " [list] [target]\n";
		return EXIT_FAILURE;
	}

	std::vector<int> v = make_int_vector_from_strings(argv + 1, argc - 1);
	const int target = v.back();
	v.pop_back();

	const auto itr = SearchFun()(v.begin(), v.end(), target);

#ifdef CSDEBUG
	std::cout << "ARRAY:\n";
	print_data(v);
#endif

	if (itr != v.end())
		std::cout << target << " FOUND AT INDEX " << (itr - v.begin()) << '\n';
	else
		std::cout << target << " NOT FOUND\n";

	return EXIT_SUCCESS;
}

#endif

