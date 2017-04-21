#ifndef CS_ALGORITHMS_LINEAR_SEARCH_HPP_
#define CS_ALGORITHMS_LINEAR_SEARCH_HPP_
#include <iterator>


template<class Itr, class T>
Itr linear_search(const Itr begin, const Itr end, const T& target)
{
	for (auto it = begin; it != end; it = std::next(it))
		if (*it == target)
			return it;

	return end;
}



#endif
