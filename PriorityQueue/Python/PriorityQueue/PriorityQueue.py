import sys
# In this implementation, index starts with 0
# parent(i) = (i-1) / 2
# left_child = 2 * i + 1
# right_child = 2 * i + 2
class PriorityQueue:
    def __init__(self, *args, **kwargs):
        self.__size = 0
        self.__arr = []

    def __len__(self):
        return self.__size
    
    def is_empty(self):
        return self.__size == 0

    def insert(self, new_val):
        self.__arr.append(new_val)
        self.__sift_up(self.__size)
        self.__size += 1

    def remove(self, pos):
        if pos < 0 or pos >= self.__size:
            raise Exception('Index is out of bound')
        val = self.__arr[pos]
        self.__arr[pos] = sys.maxsize
        self.__arr[0], self.__arr[pos] = self.__arr[pos], self.__arr[0]
        self.__sift_up(pos)
        self.extract_max()
        return val

    def get_max(self):
        if self.is_empty():
          raise Exception('Queue is empty')
        return self.__arr[0]

    def extract_max(self):
        if self.is_empty():
            raise Exception('Queue is empty')
        val = self.__arr[0]
        self.__arr[self.__size-1], self.__arr[0] = self.__arr[0], self.__arr[self.__size-1]
        self.__size -= 1
        self.__sift_down(0)
        return val
    
    def heap_sort(self, target):
        self.__build_heap(target)
        for i in range(0, len(target)-1):
            self.__arr[self.__size-1], self.__arr[0] = self.__arr[0], self.__arr[self.__size-1]
            self.__size -= 1
            self.__sift_down(0)
        return self.__arr.copy()

    def __sift_up(self, i):
        if i == 0: 
            return
        parent = (i-1) // 2
        if self.__arr[i] > self.__arr[parent]:
            self.__arr[i], self.__arr[parent] = self.__arr[parent], self.__arr[i]
            self.__sift_up(parent)

    def __sift_down(self, i):
        max_index = i
        l = 2 * i + 1
        r = 2 * i + 2
        if l < self.__size and self.__arr[l] > self.__arr[max_index]:
            max_index = l
        if r < self.__size and self.__arr[r] > self.__arr[max_index]:
            max_index = r
        if i != max_index:
            self.__arr[i], self.__arr[max_index] = self.__arr[max_index], self.__arr[i]
            self.__sift_down(max_index)

    def __build_heap(self, target):
        self.__arr = target.copy()
        self.__size = len(target)
        for i in range(self.__size // 2 - 1, -1, -1):
            self.__sift_down(i)
