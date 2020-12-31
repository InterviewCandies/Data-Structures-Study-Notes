class DNode:
    def __init__(self, key):
        self.__key = key
        self.__prev = None
        self.__next = None

    def get_key(self):
        return self.__key

    def get_prev(self):
        return self.__prev

    def get_next(self):
        return self.__next

    def set_key(self, k):
        self.__key = k

    def set_prev(self, prev):
        self.__prev = prev

    def set_next(self, next):
        self.__next = next