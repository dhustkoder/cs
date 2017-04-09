#!/bin/python

import sys
import os

# python src top dir (cs/src/python)
sys.path.insert(0, os.path.dirname(os.path.realpath(sys.argv[0])) + "/../../")

from insertion_sort import *
from common import *


sys.exit(sort_test(insertion_sort))

