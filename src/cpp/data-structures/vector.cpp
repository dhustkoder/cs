#include <iostream>
#include "common.hpp"
#include "vector.hpp"
#include "algorithms/sorting/bubble-sort.hpp"



int main(int argc, char** argv)
{
	if (argc < 3) {
		std::cout << "Usage: " << argv[0] << " [list]\n";
		return EXIT_FAILURE;
	}

	Vector<int> vec;


	{
		std::vector<int> nums = make_int_vector_from_strings(argv + 1, argc - 1);
		for (auto x : nums)
			vec.push_back(x);
	}

	std::cout << "UNSORTED:\n";
	print_data(vec);
	bubble_sort(&vec, vec.size(), [] (int a, int b) { return a < b; });
	std::cout << "SORTED:\n";
	print_data(vec);


	return EXIT_SUCCESS;
}




