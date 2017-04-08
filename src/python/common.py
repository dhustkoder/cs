

def make_int_list_from_strings(strs):
    l = []
    for elem in strs:
        l.append(int(elem))

    return l


def print_data(data):
    for elem in data:
        print(elem)



def sort_routine(data, sortfun, compare):
    print("UNSORTED:\n")
    print_data(data)
    print("SORTED:\n")
    sortfun(data, compare)
    print_data(data)


