
from Node import Node

class BST:
    def __init__(self):
        self.__root = None

    def is_empty(self):
        return self.__root == None 

    def get_height(self):
        return self.__get_height_helper(self.__root)

    def insert(self, key):
        self.__root = self.__insert_helper(self.__root, key)

    def search(self, key): 
       return self.__search_helper(self.__root, key)
    
    def erase(self, key):
        if self.search(key): 
            self.__root = self.__erase_helper(self.__root, key)
            return True
        else:
            return False

    def inorder(self):
        self.__inorder_helper(self.__root)

    def preorder(self):
        self.__preorder_helper(self.__root)

    def postorder(self):
        self.__postorder_helper(self.__root)

    def levelorder(self):
        if not self.__root:
            return 
        queue = []
        queue.append(self.__root)
        while len(queue) > 0:
            curr = queue.pop(0)
            print(curr.get_key(), end=" ")
            if curr.get_left():
                queue.append(curr.get_left())
            if curr.get_right():
                queue.append(curr.get_right())

    def __get_height_helper(self, root):
        if root == None:
            return 0
        return max(self.__get_height_helper(root.get_left()), self.__get_height_helper(root.get_right())) + 1

    def __search_helper(self, root, key):
        if root == None:
            return False
        if root.get_key() == key:
            return True
        if root.get_key() < key:
            return self.__search_helper(root.get_right(), key)
        return self.__search_helper(root.get_left(), key)

    def __insert_helper(self, root, key):
        if root == None: 
            return Node(key)
        if root.get_key() > key:
            root.set_left(self.__insert_helper(root.get_left(), key))
        else:
            root.set_right(self.__insert_helper(root.get_right(), key))
        return root

    def __erase_helper(self, root, key):
        if root == None:
            return None 
        if root.get_key() > key:
            root.set_left(self.__erase_helper(root.get_left(), key))
        if root.get_key() < key:
            root.set_right(self.__erase_helper(root.get_right(), key))
        if root.get_key() == key:
            if not root.get_left() and not root.get_right():
                return None 
            if not root.get_left():
                return root.get_right()
            if not root.get_right():
                return root.get_left()
            successor = self.__find_successor(root.get_right())
            root.set_key(successor.get_key())
            successor.set_key(key)
            root = self.__erase_helper(root, key)
        return root

    def __find_successor(self, root):
        if root.get_left() == None:
            return root
        return self.__find_successor(self, root.get_left())

    def __inorder_helper(self, root):
        if root == None:
            return 
        self.__inorder_helper(root.get_left())
        print(root.get_key(), end=" ")
        self.__inorder_helper(root.get_right())

    def __preorder_helper(self, root):
        if root == None:
            return 
        print(root.get_key(), end=" ")
        self.__preorder_helper(root.get_left())
        self.__preorder_helper(root.get_right())

    def __postorder_helper(self, root):
        if root == None:
            return
        self.__postorder_helper(root.get_left())
        self.__postorder_helper(root.get_right())
        print(root.get_key(), end=" ")
