import ctypes
DEFAULT_CAPACITY = 32
class DynamicArray: 
    def __init__(self):
        self.size = 0
        self.capacity = DEFAULT_CAPACITY
        self.arr = self.make_array(DEFAULT_CAPACITY)

    def get_size(self):
        return self.size;

    def push_back(self, new_val): 
        if (self.size == self.capacity):
            self.resize(2 * self.capacity)
        self.arr[self.size] = new_val
        self.size += 1;

    def resize(self, new_capacity):
        new_arr = self.make_array(new_capacity)
        for i in range(0, self.size):
            new_arr[i] = self.arr[i]
        self.arr = new_arr
        self.capacity = new_capacity
        
    def make_array(self, capacity):
        return (capacity * ctypes.py_object)()
