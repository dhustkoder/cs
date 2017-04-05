#!/bin/python


def linear_search(data, value):
    for i in range(0, len(data)):
        if data[i] == value:
            return i

    return None


