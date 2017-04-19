#!/bin/python

import sys
import os

# python src top dir (cs/src/python)
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)) + "/../../")

from quick_sort import *
from common import *

sys.exit(sortTest(quickSort))

