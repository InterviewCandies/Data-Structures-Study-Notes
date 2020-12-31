
class Stack:
    def __init__(self):
        self.__list = []
    def is_empty(self):
        return len(self.__list) == 0
    def top(self):
        if self.is_empty():
            raise Exception('Can not perform this action onan empty list')
        return self.__list[0]
    def push(self, data):
        self.__list.append(data)
    def pop(self):
        return self.__list.pop(len(self.__list)-1)

  