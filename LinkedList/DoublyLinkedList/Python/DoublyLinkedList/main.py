from DoublyLinkedList import DoublyLinkedList

list = DoublyLinkedList()
# 3 2 0 1 5 3 
# 3 5 1 0 2 3 
list.push_front(1)
list.push_front(2)
list.push_front(3)
list.push_back(5)
list.push_back(3)
list.insert(2, 0)
list.remove(3)
list.reverse()
##print(list.erase(1))
#print(list.pop_front())
#print(list.pop_back())
print(list.value_n_from_end(1))
print(list.value_at(1))
print(list.search(4))
print(list.back())
print(len(list))