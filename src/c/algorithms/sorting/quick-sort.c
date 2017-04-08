#include <stdio.h>
#include <stdlib.h>
#include "../../common.h"
#include "quick-sort.h"


int main(const int argc, const char* const* const argv)
{
	return sort_test(argc, argv, quick_sort);
}
