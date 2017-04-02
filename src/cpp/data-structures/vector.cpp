#include <iostream>
#include "common.hpp"
#include "vector.hpp"




int main(int argc, char** argv)
{
	if (argc < 3) {
		std::cout << "Usage: " << argv[0] << " [list]\n";
		return EXIT_FAILURE;
	}

	Vector<int> vec;


	{
		std::vector<int> nums = make_int_vector_from_strings(argv + 1, argc - 1);
		vec.reserve(static_cast<int>(nums.size()));
		for (auto x : nums)
			vec.push_back(x);
	}


	print_data(vec);


	return EXIT_SUCCESS;
}




