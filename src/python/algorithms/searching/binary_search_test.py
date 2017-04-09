#!/bin/python

import sys
import os

sys.path.insert(0, os.path.dirname(os.path.realpath(sys.argv[0])) + "/../../")
sys.path.insert(0, os.path.dirname(os.path.realpath(sys.argv[0])) + "/../sorting/")

from binary_search import *
from quick_sort import *
from common import *


def binary_sort_prep(data, target):
    quick_sort(data, lambda a, b: (a < b))
    return binary_search(data, target)

sys.exit(search_test(binary_sort_prep))




