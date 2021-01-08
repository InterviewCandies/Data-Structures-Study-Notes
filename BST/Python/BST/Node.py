class Node:
    def __init__(self, key):
        self.__key = key
        self.__left = None
        self.__right = None
    
    def get_key(self):
        return self.__key
    
    def get_left(self):
        return self.__left

    def get_right(self):
        return self.__right

    def set_key(self, key):
        self.__key = key

    def set_left(self, left):
        self.__left = left

    def set_right(self, right):
        self.__right = right
