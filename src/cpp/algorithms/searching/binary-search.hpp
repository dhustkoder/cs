#ifndef CS_ALGORITHMS_BINARY_SEARCH_HPP_
#define CS_ALGORITHMS_BINARY_SEARCH_HPP_


template<class Itr, class T>
Itr binary_search(const Itr begin, const Itr end, const T& target)
{
	const int size = static_cast<int>(end - begin);
	int min = 0;
	int max = size - 1;

	while (min <= max) {
		const int guess = (min + max) / 2;
		if (*(begin + guess) < target)
			min = guess + 1;
		else if (*(begin + guess) > target)
			max = guess - 1;
		else
			return begin + guess;
	}

	return end;
}




#endif
