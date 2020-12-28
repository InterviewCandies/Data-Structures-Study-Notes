class Node:
    def __init__(self, key):
        self.__key = key
        self.__next = None

    def get_key(self):
        return self.__key

    def get_next(self):
        return self.__next

    def set_key(self, key):
        self.__key = key

    def set_next(self, node):
        self.__next = node
    