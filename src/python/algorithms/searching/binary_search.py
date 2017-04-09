#!/bin/python


def binary_search(data, target):
    l = 0
    r = len(data) - 1
    while r >= l:
        guess = int((l + r) / 2)
        if data[guess] < target:
            l = guess + 1
        elif data[guess] > target:
            r = guess - 1
        else:
            return guess

    return None


