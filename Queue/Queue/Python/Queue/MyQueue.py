class MyQueue:
    def __init__(self):
        self.__list = []
    def is_empty(self):
        return len(self.__list) == 0;
    def front(self):
        if self.is_empty():
            raise Exception('Can not perform this on a empty queue')
        return self.__list[0];
    def enqueue(self, data):
        self.__list.append(data)
    def dequeue(self):
        if self.is_empty():
           raise Exception('Can not perform this on a empty queue')
        return self.__list.pop(0);
