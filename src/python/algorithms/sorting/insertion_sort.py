#!/bin/python

def insertion_sort(data, compare):

    for n in range(1, len(data)):
        j = n
        while j > 0 and compare(data[j], data[j - 1]):
            aux = data[j - 1]
            data[j - 1] = data[j]
            data[j] = aux
            j -= 1

    return data

