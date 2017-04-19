#!/bin/python


def linearSearch(data, value):
    for i in range(0, len(data)):
        if data[i] == value:
            return i

    return None


