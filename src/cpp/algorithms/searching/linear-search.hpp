#ifndef CS_ALGORITHMS_LINEAR_SEARCH_HPP_
#define CS_ALGORITHMS_LINEAR_SEARCH_HPP_


template<class Itr, class T>
Itr linear_search(const Itr begin, const Itr end, const T& target)
{
	for (Itr itr = begin; itr != end; ++itr)
		if (*itr == target)
			return itr;

	return end;
}



#endif
