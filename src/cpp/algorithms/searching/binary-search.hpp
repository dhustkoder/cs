#ifndef CS_ALGORITHMS_BINARY_SEARCH_HPP_
#define CS_ALGORITHMS_BINARY_SEARCH_HPP_
#include <iterator>


template<class Itr, class T>
Itr binary_search(const Itr begin, const Itr end, const T& target)
{
	int min = 0;
	int max = std::distance(begin, end) - 1;

	while (min <= max) {
		const int guess = (min + max) / 2;
		const auto it = std::next(begin, guess);
		if (*it < target)
			min = guess + 1;
		else if (*it > target)
			max = guess - 1;
		else
			return it;
	}

	return end;
}




#endif
