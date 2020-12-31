from DNode import DNode
class DoublyLinkedList:
    def __init__(self):
        self.__head = None
        self.__tail = None
        self.__size = 0
    
    def __len__(self):
        return self.__size

    def is_empty(self):
        return self.__head != None

    def front(self):
        if self.__head == None:
            raise Exception("Can not perform this action on an empty list")
            return
        return self.__head.get_key()

    def back(self):
        if self.__head == None:
            raise Exception("Can not perform this action on an empty list")
            return
        return self.__tail.get_key()        
    
    def value_at(self, pos):
        if pos < 0 or pos >= self.__size:
            raise Exception("Index is out of bound")
        curr = self.__head
        while pos > 0:
            curr = curr.get_next()
            pos -= 1
        return curr.get_key()

    def search(self, k):
        return self.__find_index(k) != -1

    def push_front(self, k):
        new_node = DNode(k)
        self.__size += 1
        if self.__head == None:
            self.__head = self.__tail = new_node
            return
        new_node.set_next(self.__head);
        self.__head.set_prev(new_node);
        self.__head = new_node;

    def push_back(self, k): 
        new_node = DNode(k)
        self.__size += 1
        if self.__head == None:
            self.__head = self.__tail = new_node
            return
        self.__tail.set_next(new_node)
        new_node.set_prev(self.__tail)
        self.__tail = new_node

    def pop_front(self):
        if self.__head == None:
            raise Exception("Can not perform this action on an empty list")
        val = self.__head.get_key()
        self.__size -= 1
        if self.__head == self.__tail:
            self.__head = self.__tail = None
            return val
        self.__head.get_next().set_prev(None)
        self.__head = self.__head.get_next()
        return val;

    def pop_back(self):
        if self.__head == None:
            raise Exception("Can not perform this action on an empty list")
        val = self.__tail.get_key()
        self.__size -= 1
        if self.__head == self.__tail:
            self.__head = self.__tail = None
            return val
        self.__tail.get_prev().set_next(None)
        self.__tail = self.__tail.get_prev()
        return val

    def insert(self, pos, k):
        if pos < 0 or pos > self.__size:
            raise Exception("Index is out of bound")
        if pos == 0:
            self.push_front(k)
            return
        if pos == self.__size:
            self.push_back(k)
            return 
        new_node = DNode(k)
        p = self.__find_by_index(pos)
        p.get_prev().set_next(new_node)
        new_node.set_prev(p.get_prev())
        p.set_prev(new_node)
        new_node.set_next(p)
        self.__size += 1

    def erase(self, pos):
        if pos < 0 or pos >= self.__size:
            raise Exception("Index us out of bound")
        if pos == 0:
            return self.pop_front()
        if pos == self.__size-1:
            return self.pop_back()
        p = self.__find_by_index(pos)
        p.get_prev().set_next(p.get_next())
        p.get_next().set_prev(p.get_prev())
        self.__size -= 1
        return p.get_key()

    def remove(self, k):
        pos = self.__find_index(k)
        while pos >= 0:
            self.erase(pos)
            pos = self.__find_index(k)
   
    def value_n_from_end(self, n):
        return self.value_at(self.__size - n - 1)
    
    def reverse(self):
        prev = None
        curr = self.__head
        while curr:
            next = curr.get_next()
            curr.set_next(prev)
            if prev:
                prev.set_prev(curr)
            prev = curr
            curr = next
        self.__tail = self.__head 
        self.__head = prev

    def __find_index(self, k):
        pos = 0
        curr = self.__head
        while curr:
            if curr.get_key() == k:
                return pos
            curr = curr.get_next()
            pos += 1
        return -1
    
    def __find_by_index(self, pos):
        curr = self.__head
        while pos > 0:
            curr = curr.get_next()
            pos -= 1
        return curr
