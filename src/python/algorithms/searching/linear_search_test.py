#!/bin/python

import sys
import os

sys.path.insert(0, os.path.dirname(os.path.realpath(sys.argv[0])) + "/../../")

from linear_search import *
from common import *


sys.exit(search_routine(linear_search))



