#!/bin/python

from vector import *

v = Vector()
a = ["Hello ", " World", 1, 2, 3, "dlroW ", " olleH"]

for e in a:
    v.push_back(e)

for e in v:
    print(e)


