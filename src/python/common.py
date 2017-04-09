#!/bin/python

import logging
import sys
import os


logging.basicConfig(stream=sys.stdout, level=logging.DEBUG)


def sort_test(sortfun):
    data = [int(i) for i in sys.argv[1:]]

    if len(data) < 2:
        print("Usage: " + sys.argv[0] + " [list]")
        return os.EX_USAGE

    logging.debug("UNSORTED:")
    logging.debug(data)
    logging.debug("SORTED:")
    sortfun(data, lambda a, b: (a < b))
    logging.debug(data)
    return os.EX_OK


def search_test(searchfun):
    data = [int(i) for i in sys.argv[1:-1]]
    
    if len(data) < 2:
        print("Usage: " + sys.argv[0] + " [list]")
        return os.EX_USAGE

    target = int(sys.argv[len(sys.argv) - 1])
    index = searchfun(data, target)

    logging.debug("ARRAY:")
    logging.debug(data)

    if index != None:
        print(str(target) + " FOUND AT INDEX " + str(index))
    else:
        print(str(target) + " NOT FOUND")


    return os.EX_OK
    
