#include "common.hpp"
#include "binary-search.hpp"


struct SearchFun {
	template<class Itr, class T>
	Itr operator()(const Itr begin, const Itr end, const T& target) &&
	{
		return binary_search(begin, end, target);
	}
};


int main(int argc, const char** argv)
{
	return search_test<SearchFun>(argc, argv);
}
