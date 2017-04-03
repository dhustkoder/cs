#include <cstdlib>
#include <iostream>
#include <vector>
#include "common.hpp"
#include "bubble-sort.hpp"

int main(int argc, char** argv)
{
	if (argc < 3) {
		std::cerr << "Usage: " << argv[0] << " [list]\n";
		return EXIT_FAILURE;
	}

	std::vector<int> v = make_int_vector_from_strings(argv + 1, argc - 1);
	bubble_sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

	print_data(v);
	return EXIT_SUCCESS;
}







