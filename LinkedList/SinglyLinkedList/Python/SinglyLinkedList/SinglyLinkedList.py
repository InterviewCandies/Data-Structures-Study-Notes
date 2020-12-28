from Node import Node
class SinglyLinkedList:
    def __init__(self):
        self.__head = None
        self.__tail = None
        self.__size = 0

    def __len__(self):
        return self.__size

    def is_empty(self):
        return self.__size == 0

    def front(self):
        if self.__head == None: 
            raise Exception('Can not perform this action on an empty list.')
            return
        return self.__head.get_key()

    def back(self):
        if self.__tail == None: 
            raise Exception('Can not perform this action on an empty list.')
            return
        return self.__tail.get_key()

    def value_at(self, pos):
        if pos < 0 or pos >= self.__size:
            raise Exception('Index is out of bound')
        curr = self.__head
        while pos > 0:
            curr = curr.get_next()
            pos -= 1
        return curr.get_key()

    def search(self, key):
        return self.__findByKey(key) != -1

    def push_front(self, key):
        new_node = Node(key)
        self.__size += 1
        if self.__head == None:
            self.__head = self.__tail = new_node
            return
        new_node.set_next(self.__head)
        self.__head = new_node
        
    def push_back(self, key):
        new_node = Node(key)
        self.__size += 1
        if self.__head == None:
            self.__head = self.__tail = new_node
            return
        self.__tail.set_next(new_node)
        self.__tail = new_node

    def pop_front(self):
       if self.__head == None: 
            raise Exception('Can not perform this action on an empty list.')
            return
       val = self.__head.get_key()
       self.__size -= 1
       if self.__head == self.__tail:
           self.__head = self.__tail = None
           return val
       self.__head = self.__head.get_next()
       return val
 
    def pop_back(self):
       if self.__head == None: 
            raise Exception('Can not perform this action on an empty list.')
            return
       val = self.__tail.get_key()
       if self.__head == self.__tail:
           self.__head = self.__tail = None
           self.__size -= 1
           return val
       prev_node = self.__findPrevNode(self.__size-1)
       prev_node.set_next(None)
       self.__tail = prev_node
       self.__size -= 1
       return val

    def insert(self, key, pos):
       if pos < 0 or pos > self.__size:
           raise Exception('Index is out of bound')
       if pos == 0:
           self.push_front(key)
           return
       if pos == self.__size:
           self.push_back(key)
           return
       new_node = Node(key)
       prev_node = self.__findPrevNode(pos)
       new_node.set_next(prev_node.get_next())
       prev_node.set_next(new_node)
       self.__size += 1

    def erase(self, pos):
        if pos < 0 or pos >= self.__size:
            raise Exception('Index is out of bound')
        if pos == 0:
            return self.pop_front()
        if pos == self.__size-1:
            return self.pop_back()
        prev_node = self.__findPrevNode(pos)
        val = prev_node.get_next().get_key()
        prev_node.set_next(prev_node.get_next().get_next())
        self.__size -= 1
        return val

    def remove(self, key):
        pos = self.__findByKey(key)
        while pos >= 0:
            self.erase(pos)
            pos = self.__findByKey(key)

    def reverse(self):
        if self.is_empty():
            return
        prev = None
        curr = self.__head
        while curr is not None:
            next = curr.get_next()
            curr.set_next(prev)
            prev = curr
            curr = next
        self.__tail = self.__head
        self.__head = prev

    def value_n_from_end(self, n):
        return self.value_at(self.__size - n - 1)
   
    def __findByKey(self, key):
        p = self.__head
        pos = 0
        while p != None:
            if p.get_key() == key:
                return pos
            p = p.get_next()
            pos += 1
        return -1

    def __findPrevNode(self, pos):
        if pos == 0:
           return None
        p = self.__head
        pos -= 1
        while pos > 0:
            p = p.get_next()
            pos -= 1
        return p
