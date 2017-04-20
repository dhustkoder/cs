#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "linear-search.h"
#include "data-structures/ds-generics.h"



int main(const int argc, const char* const * const argv)
{
	return search_test(argc, argv, linear_search);
}

