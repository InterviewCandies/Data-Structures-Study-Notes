#pragma once
#include "../../../../LinkedList//DoublyLinkedList/C++//DoublyLinkedList//DoublyLinkedList.h"
#include <vector>
template<typename T>
class Queue {
public:
	Queue() = default;
	~Queue() = default;
	bool IsEmpty() {
		return list.IsEmpty();
	}
	T Front() {
		return list.Front();
	}
	void Push(T data) {
		return list.PushBack(data);
	}
	T Pop() {
		return list.PopFront();
	}
private:
	DoublyLinkedList<T> list;
};