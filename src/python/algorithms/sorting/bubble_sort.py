#!/bin/python

def bubbleSort(data, compare):
    for i in range(0, len(data)):
        for j in range(0, (len(data) - 1) - i):
            if compare(data[j + 1], data[j]):
                aux = data[j + 1]
                data[j + 1] = data[j]
                data[j] = aux
    return data

