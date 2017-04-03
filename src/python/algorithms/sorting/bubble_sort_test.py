#!/bin/python

import sys
import os

# python src top dir (cs/src/python)
sys.path.insert(0, os.path.dirname(os.path.realpath(sys.argv[0])) + "/../../")

from bubble_sort import bubble_sort
from common import *

nums = make_int_list_from_strings(sys.argv[1:])

if len(nums) < 2:
    print("Usage: " + sys.argv[0] + " [list]")
    sys.exit(os.EX_USAGE)

print ("UNSORTED:")

for n in nums:
    print(n)

bubble_sort(nums, lambda a, b: (a < b))

print("SORTED:")

for n in nums:
    print(str(n))


sys.exit(os.EX_OK)

