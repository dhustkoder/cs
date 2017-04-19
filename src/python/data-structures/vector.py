#!/bin/python


class Vector:
    'Sequencial Container'

    def __init__(self):
        self.currentIdx = 0
        self.data = list()


    def __next__(self):
        if self.currentIdx < len(self.data):
            idx = self.currentIdx
            elem = self.data[idx]
            self.currentIdx += 1
            return (idx, elem)
        else:
            self.currentIdx = 0
            raise StopIteration


    def __iter__(self):
        return self


    def __len__(self):
        return len(self.data)


    def __getitem__(self, key):
        return self.data[key]
    
    
    def __setitem__(self, key, value):
        self.data[key] = value
        return self.data[key]



    def size(self):
        return len(self.data)


    def pushBack(self, value):
        self.data.append(value)


    def popBack(self):
        elem = self.data[len(self.data) - 1]
        self.data.pop(len(self.data) - 1)
        return elem

