from MyQueue import MyQueue
queue = MyQueue()
queue.enqueue(2)
queue.enqueue(1)
queue.enqueue(3)
print(queue.dequeue())
print(queue.dequeue())
print(queue.dequeue())