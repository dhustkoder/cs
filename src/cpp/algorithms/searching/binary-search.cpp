#include <iostream>
#include <vector>
#include <string>
#include "common.hpp"
#include "binary-search.hpp"
#include "algorithms/sorting/quick-sort.hpp"


struct SearchFun {
	template<class Itr, class T>
	Itr operator()(const Itr begin, const Itr end, const T& target) {
		quick_sort(begin, end, [](int a, int b) { return a < b; });
		return binary_search(begin, end, target);
	}
};


int main(int argc, const char** argv)
{
	return search_test<SearchFun>(argc, argv);
}
