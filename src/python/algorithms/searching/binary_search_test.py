#!/bin/python

import sys
import os

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)) + "/../../")
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)) + "/../sorting/")

from binary_search import *
from quick_sort import *
from common import *


sys.exit(searchTest(binarySearch))




