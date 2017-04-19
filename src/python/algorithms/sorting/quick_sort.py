#!/bin/python


def quickSortPart(l, r, data, compare):
    p = l
    l = l + 1
    r = r - 1

    while True:

        while l < r and compare(data[l], data[p]):
            l += 1

        while r >= l and compare(data[p], data[r]):
            r -= 1
        
        if l >= r:
            break

        tmp = data[l]
        data[l] = data[r]
        data[r] = tmp

        l += 1
        r -= 1

    tmp = data[r]
    data[r] = data[p]
    data[p] = tmp

    return r


def quickSort(data, compare):


    def qsortImpl(l, r, data, compare):
        if (r - l) > 1:
            p = quickSortPart(l, r, data, compare)
            qsortImpl(p + 1, r, data, compare)
            qsortImpl(l, p, data, compare)

    qsortImpl(0, len(data), data, compare)
    return data

