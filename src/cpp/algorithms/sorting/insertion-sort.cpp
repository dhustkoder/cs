#include <iostream>
#include "insertion-sort.hpp"
#include "common.hpp"


struct SortFun {
	template<class T, class CmpFun>
	void operator()(T begin, T end, CmpFun cmpfun) && {
		return insertion_sort(begin, end, cmpfun);
	}
};


int main(int argc, char** argv)
{
	return sort_test<SortFun>(argc, argv);
}
