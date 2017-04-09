#!/bin/python

import sys
import os

def make_int_list_from_strings(strs):
    l = []
    for elem in strs:
        l.append(int(elem))

    return l


def print_data(data):
    for elem in data:
        print(elem)

        
def sort_routine(sortfun):
    nums = make_int_list_from_strings(sys.argv[1:])

    if len(nums) < 2:
        print("Usage: " + sys.argv[0] + " [list]")
        return os.EX_USAGE

    print ("UNSORTED:")
    print_data(nums)
    print("SORTED:")
    sortfun(nums, lambda a, b: (a < b))
    print_data(nums)
    return os.EX_OK


def search_routine(searchfun):
    data = make_int_list_from_strings(sys.argv[1:-1])
    target = int(sys.argv[len(sys.argv) - 1])

    if len(data) < 3:
        print("Usage: " + sys.argv[0] + " [list] [target]")
        return os.EX_USAGE

    index = searchfun(data, target)

    if index != None:
        print("Found " + str(target) + " at index \'" + str(index) + "\'")
    else:
        print("Not Found " + str(target))


    return os.EX_OK
    