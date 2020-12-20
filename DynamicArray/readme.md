# Dynamic array

## What is an array?

- Contiguous chunks of memory
- Consisting of equal-size elements
- Indexed by contiguous integers
- Constant time access

## What is dynamic array?

- Resizable array
- Abstract Data Types (ADT)
- Can initialize without knowing it size

## Idea of dynamic array

Store a pointer to a dynamically-allocated array and replace it with a newlly-allocated array when needed

## Table doubling

- When size is equal to capacity, increase capacity by 2
- When size is equal or less than to capacity / 4, descrease capacity by 2 (Only resize when size <= capacity / 4 to secure amortized constant time in push_back)

## Time complexity of Dynamic array

| Case         | Access | Push back | Pop back | Insert | Remove |
| ------------ | ------ | --------- | -------- | ------ | ------ |
| Average case | O(1)   | O(1)\*    | O(1)\*   | O(n)   | O(n)   |
| Worst case   | O(1)   | O(n)      | O(n)     | O(n)   | O(n)   |

"\*" amortized

## Reference

- https://www.coursera.org/lecture/data-structures/arrays-OsBSF
- https://www.coursera.org/lecture/data-structures/dynamic-arrays-EwbnV
