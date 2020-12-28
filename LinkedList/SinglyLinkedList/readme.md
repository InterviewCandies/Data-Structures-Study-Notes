# Linked List

## Definition

A linked list is a linear data structures, in which elements are **not stored at contiguos memory locations**

## Singly linked list

### Definition

A singly linked list consists of nodes where each node contains a data field and a reference to the next node in the list.\
![sll](../../img/sll.png)

### Operations

- push_back() : O(1) with tail pointer / O(n) without tail pointer
- pop_back() : O(n)
- push_front() : O(1)
- pop_front() : O(1)
- insert() : O(1) (but finding the right position costs O(n))
- remove() : O(1) (but finding the right position costs O(n))
