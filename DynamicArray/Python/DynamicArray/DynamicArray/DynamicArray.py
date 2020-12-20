import ctypes
DEFAULT_CAPACITY = 32

class DynamicArray:
    def __init__(self):
        self.__size = 0
        self.__capacity = DEFAULT_CAPACITY
        self.__arr = self.__make_array(DEFAULT_CAPACITY)

    def __len__(self):
        return self.__size

    def __getitem__(self, pos):
        if pos < 0 or pos >= self.__size:
            raise Exception('Index is out of bound')
        return self.__arr[pos]
    
    def __repr__(self):
        res = str(self.__arr[0]) if self.__size != 0 else '' 
        for i in range(1, self.__size):
            res = res + ' ' +  str(self.__arr[i])
        return res
    
    def push_back(self, new_val):
        if self.__size == self.__capacity:
            self.__resize(2 * self.__capacity)
        self.__arr[self.__size] = new_val
        self.__size += 1

    def pop_back(self):
        if self.__size == 0:
            raise Exception('Array is empty')
        val = self.__arr[self.__size-1]
        self.__size -=1
        if self.__size <= self.__capacity // 4:
           self.__resize(self.__capacity // 2)
        return val

    def insert(self, pos, new_val):    #insert new element at given postition
        if pos < 0 or pos > self.__size:
            raise Exception('Index is out of bound')
        if self.__size == self.__capacity:
            self.__resize(2 * self.__capacity)
        self.__size += 1
        for i in range(self.__size-1, pos, -1):
            self.__arr[i] = self.__arr[i-1]
        self.__arr[pos] = new_val

    def remove(self, pos):      #remove an element at given position
        if pos < 0 or pos >= self.__size:
            raise Exception('Index is out of bound')
        self.__size -= 1
        val = self.__arr[pos]
        for i in range(pos, self.__size):
            self.__arr[i] = self.__arr[i+1]
        if self.__size == self.__capacity / 4:
            self.__resize(self.__capacity / 2)
        return val

    def reverse(self):
        for i in range(0, self.__size // 2):
            self.__arr[i], self.__arr[self.__size - i - 1] = self.__arr[self.__size - i - 1], self.__arr[i]

    def __make_array(self, capacity):
        return (capacity * ctypes.py_object)() #Create an array with given capacity

    def __resize(self, new_capacity):
        new_arr = self.__make_array(new_capacity)
        for i in range(0, self.__size):
            new_arr[i] = self.__arr[i]
        self.__arr = new_arr
        self.__capacity = new_capacity

        