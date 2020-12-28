#pragma once
#include "Node.h"
#include <assert.h>
#include <memory>
using namespace std;
template <typename T>
class SinglyLinkedList {
public:
	SinglyLinkedList() {
		head = tail = nullptr;
		size = 0;
	}

	~SinglyLinkedList() = default;

	bool IsEmpty() {
		return size == 0;
	}

	int GetSize() {
		return size;
	}

	T ValueAt(int pos) {
		assert(pos >= 0 && pos < size);
		shared_ptr<Node<T>> p = head;
		while (pos--) p = p->GetNext();
		return p->GetKey();
	}

	bool Search(T val) {
		return FindIndex(val) != -1;
	}

	void PushBack(T k) {
		shared_ptr<Node<T>> p(new Node<T>(k));
		size++;
		if (!head) {
			head = tail = p;
			return;
		}
		tail->SetNext(p);
		tail = p;
	}

	T PopBack() {
		assert(!IsEmpty());
		shared_ptr<Node<T>> prevNode = FindPrevNodeByIndex(size - 1);
		T key = tail->GetKey();
		if (prevNode) prevNode->SetNext(nullptr);
		else head = nullptr;
		tail = prevNode;
		size--;
		return key;
	}

	void PushFront(T k) {
		shared_ptr<Node<T>> p(new Node<T>(k));
		size++;
		if (!head) {
			head = tail = p;
			return;
		}
		p->SetNext(head);
		head = p;
	} 

	T PopFront() {
		assert(!IsEmpty());
		size--;
		T key = head->GetKey();
		if (head == tail) {
			head = tail = nullptr;
			return key;
		}
		head = head->GetNext();
		return key;
	}

	void Insert(int pos, T k) {
		assert(pos >= 0 && pos <= size);
		if (!pos) {
			PushFront(k);
			return;
		}
		if (pos == size) {
			PushBack(k);
			return;
		}
		shared_ptr<Node<T>> p = make_shared<Node<T>>(k);
		auto prevNode = FindPrevNodeByIndex(pos);
		p->SetNext(prevNode->GetNext());
		prevNode->SetNext(p);
		size++;
	}
	
	T Erase(int pos) {
		assert(pos >= 0 && pos < size);
		if (!pos) return PopFront();
		if (pos == size - 1) return PopBack();
		auto prevNode = FindPrevNodeByIndex(pos);
		T key = prevNode->GetNext()->GetKey();
		prevNode->SetNext(prevNode->GetNext()->GetNext());
		size--;
		return key;
	}

	void Remove(T key) {
		auto pos = FindIndex(key);
		while (pos >= 0) {
			Erase(pos);
			pos = FindIndex(key);
		}
	}

	void Reverse() {
		shared_ptr<Node<T>> prevNode = nullptr;
		auto p = head;
		while (p) {
			auto next = p->GetNext();
			p->SetNext(prevNode);
			prevNode = p;
			p = next;
		}
		tail = head;
		head = prevNode;
	}
	
	T ValueNFromEnd(int n) {
		assert(n >= 0 && n < size);
		return ValueAt(size - n - 1);
	}

private:
	shared_ptr<Node<T>> head;
	shared_ptr<Node<T>> tail;
	shared_ptr<Node<T>> FindPrevNodeByIndex(int pos) {
		if (pos == 0) return nullptr;
		shared_ptr<Node<T>> p = head;
		while (--pos) p = p->GetNext();
		return p;
	}
	int FindIndex(T key) {
		int pos = 0;
		auto  p = head;
		while (p) {
			if (p->GetKey() == key) return pos;
			p = p->GetNext();
			pos++;
		}
		return -1;
	}
	int size;
};