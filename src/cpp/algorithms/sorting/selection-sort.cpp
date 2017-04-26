#include "common.hpp"
#include "selection-sort.hpp"


struct SortFun {
	template<class T, class CmpFun>
	void operator()(T begin, T end, CmpFun cmpfun) &&
	{
		return selection_sort(begin, end, cmpfun);
	}
};

int main(int argc, char** argv)
{
	return sort_test<SortFun>(argc, argv);
}
