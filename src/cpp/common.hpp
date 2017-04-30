#ifndef CS_COMMON_HPP_
#define CS_COMMON_HPP_
#include <cstring>
#include <iostream>
#include <string>
#include "data-structures/vector.hpp"


template<class T>
Vector<T> create_ds_from_strings(const char* const* strs, const int size);

template<>
Vector<int> create_ds_from_strings<int>(const char* const* strs, const int size)
{
	Vector<int> r;
	r.reserve(size);

	for (int i = 0; i < size; ++i)
		r.push_back(static_cast<int>(std::strtol(strs[i], NULL, 0)));

	return r;
}

template<>
Vector<std::string> create_ds_from_strings<std::string>(const char* const* strs, const int size)
{
	Vector<std::string> r;
	r.reserve(size);

	for (int i = 0; i < size; ++i)
		r.push_back(strs[i]);
	
	return r;
}



template<class T>
void print_data(const T& data)
{
	const int limit = static_cast<int>(data.size());
	for (int i = 0; i < limit; ++i)
		std::cout << '[' << i << "] = " << data[i] << '\n';
}


template<class SortFun>
int sort_test(const int argc, const char* const * argv)
{
	if (argc < 3) {
		std::cerr << "Usage: " << argv[0] << " [list]\n";
		return EXIT_FAILURE;
	}

	auto ds = create_ds_from_strings<int>(argv + 1, argc - 1);

#ifdef CSDEBUG
	std::cout << "UNSORTED:\n";
	print_data(ds);
#endif

	SortFun()(ds.begin(), ds.end(), std::less<decltype(*ds.cbegin())>());

#ifdef CSDEBUG
	std::cout << "SORTED:\n";
	print_data(ds);
#endif

	return EXIT_SUCCESS;
}


template<class SearchFun>
int search_test(const int argc, const char* const * argv)
{
	if (argc < 4) {
		std::cerr << "Usage: " << argv[0] << " [list] [target]\n";
		return EXIT_FAILURE;
	}

	auto ds = create_ds_from_strings<int>(argv + 1, argc - 1);
	const auto target = ds.pop_back();
	const auto itr = SearchFun()(ds.begin(), ds.end(), target);

#ifdef CSDEBUG
	std::cout << "ARRAY:\n";
	print_data(ds);
#endif

	if (itr != ds.end())
		std::cout << target << " FOUND AT INDEX " << (itr - ds.begin()) << '\n';
	else
		std::cout << target << " NOT FOUND\n";

	return EXIT_SUCCESS;
}

#endif

