#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "common.h"
#include "binary-search.h"
#include "algorithms/sorting/quick-sort.h"


int main(const int argc, const char* const * const argv)
{
	return search_test(argc, argv, binary_search);
}

