#include <stdio.h>
#include <stdlib.h>
#include "../../common.h"
#include "bubble-sort.h"


int main(const int argc, const char* const* const argv)
{
	return sort_test(argc, argv, bubble_sort);
}
