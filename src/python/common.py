#!/bin/python

import logging
import sys
import os

logging.basicConfig(stream=sys.stdout, level=logging.ERROR)

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)) + "/data-structures/")

from vector import *


def makeIntVectorFromStrings(strings):
    data = Vector()
    for str in strings:
        data.pushBack(int(str))
    return data


def printData(data):
    for elem in data:
        logging.debug(elem)


def sortTest(sortfun):

    data = makeIntVectorFromStrings(sys.argv[1:]);

    if data.size() < 2:
        print("Usage: " + sys.argv[0] + " [list]")
        return os.EX_USAGE

    logging.debug("UNSORTED:")
    printData(data)
    logging.debug("SORTED:")
    sortfun(data, lambda a, b: (a < b))
    printData(data)
    return os.EX_OK


def searchTest(searchfun):

    data = makeIntVectorFromStrings(sys.argv[1:])
    
    if data.size() < 2:
        print("Usage: " + sys.argv[0] + " [list]")
        return os.EX_USAGE

    target = data.popBack()
    index = searchfun(data, target)

    logging.debug("ARRAY:")
    printData(data)

    if index != None:
        print(str(target) + " FOUND AT INDEX " + str(index))
    else:
        print(str(target) + " NOT FOUND")


    return os.EX_OK
    
