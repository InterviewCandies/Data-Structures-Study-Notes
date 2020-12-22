
from PriorityQueue import PriorityQueue

pq = PriorityQueue()
pq.insert(2)
pq.insert(1)
pq.insert(5)
pq.insert(3)
pq.insert(5)
print(pq.extract_max())
print(pq.remove(1))
print(pq.extract_max())
print(len(pq))
A = [1,9,4,2,4,5,1]
A = pq.heap_sort(A) # A new heap is create base on A
print(A)