

def selectionSort(data, compare):
    for i in range(0, data.size()):
        min_index = i

        for j in range(i, data.size()):
            if compare(data[j], data[min_index]):
                min_index = j

        if min_index != i:
            tmp = data[min_index]
            data[min_index] = data[i]
            data[i] = tmp
