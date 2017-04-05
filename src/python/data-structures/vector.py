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
            self.currentIdx = self.currentIdx + 1
            return (idx, elem)
        else:
            self.currentIdx = 0
            raise StopIteration


    def __iter__(self):
        return self




    def size(self):
        return len(self.data)


    def push_back(self, value):
        self.data.append(value)


    def pop_back(self, value):
        self.data.erase(len(data) - 1)

