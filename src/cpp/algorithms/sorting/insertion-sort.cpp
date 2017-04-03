#include <iostream>
#include "insertion-sort.hpp"
#include "common.hpp"



int main(int argc, char** argv)
{
	if (argc < 3) {
		std::cout << "Usage: " << argv[0] << "[list]\n";
		return EXIT_FAILURE;
	}

	std::vector<int> v = make_int_vector_from_strings(argv + 1, argc - 1);
	insertion_sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

	print_data(v);
	return EXIT_SUCCESS;
}




