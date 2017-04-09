#!/bin/python

import sys
import os

def make_int_list_from_strings(strs):
    l = []
    for elem in strs:
        l.append(int(elem))

    return l


def sort_test(sortfun):
    data = make_int_list_from_strings(sys.argv[1:])

    if len(data) < 2:
        print("Usage: " + sys.argv[0] + " [list]")
        return os.EX_USAGE

    print("UNSORTED:")
    print(data)
    print("SORTED:")
    sortfun(data, lambda a, b: (a < b))
    print(data)
    return os.EX_OK


def search_test(searchfun):
    data = make_int_list_from_strings(sys.argv[1:-1])

    if len(data) < 3:
        print("Usage: " + sys.argv[0] + " [list] [target]")
        return os.EX_USAGE

    target = int(sys.argv[len(sys.argv) - 1])
    index = searchfun(data, target)

    print("ARRAY:")
    print(data)

    if index != None:
        print(str(target) + " FOUND AT INDEX " + str(index))
    else:
        print(str(target) + " NOT FOUND")


    return os.EX_OK
    
