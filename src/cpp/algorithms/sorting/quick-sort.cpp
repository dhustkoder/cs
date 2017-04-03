#include <iostream>
#include "common.hpp"
#include "quick-sort.hpp"




int main(int argc, const char** argv)
{
	if (argc < 3) {
		std::cout << "Usage: " << argv[0] << " [list]\n";
		return EXIT_FAILURE;
	}

	std::vector<int> v = make_int_vector_from_strings(argv + 1, argc - 1);
	std::cout << "UNSORTED: \n";
	print_data(v);

	quick_sort(v.begin(), v.end(), [] (int a, int b) { return a < b; });
	std::cout << "SORTED: \n";
	print_data(v);


	return EXIT_SUCCESS;
}




