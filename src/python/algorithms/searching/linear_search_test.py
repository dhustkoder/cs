#!/bin/python

import sys
import os

sys.path.insert(0, os.path.dirname(os.path.realpath(sys.argv[0])) + "/../../")

from linear_search import *
from common import *


data = make_int_list_from_strings(sys.argv[1:-1])
target = int(sys.argv[len(sys.argv) - 1])

if len(data) < 3:
    print("Usage: " + sys.argv[0] + " [list] [target]")
    sys.exit(os.EX_USAGE)


index = linear_search(data, target)

if index != None:
    print("Found " + str(target) + " at index \'" + str(index) + "\'")
else:
    print("Not Found " + str(target))


sys.exit(os.EX_OK)



