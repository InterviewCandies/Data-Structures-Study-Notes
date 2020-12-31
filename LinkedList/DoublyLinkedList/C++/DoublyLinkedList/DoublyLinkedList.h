#pragma once
#include "DNode.h"
#include <assert.h>
#include <iostream>
template<typename T>
class DoublyLinkedList {
public:
	DoublyLinkedList() {
		head = tail = nullptr;
		size = 0;
	}
	~DoublyLinkedList() = default;
	bool IsEmpty() {
		return head == nullptr;
	}
	int GetSize() {
		return size;
	}
	T Front() {
		assert(!IsEmpty());
		return head->GetKey();
	}
	T Back() {
		assert(!IsEmpty());
		return tail->GetKey();
	}
	bool Search(T k) {
		return FindIndex(k) != -1;
	}
	T ValueAt(int pos) {
		assert(pos >= 0 && pos < size);
		return FindByIndex(pos)->GetKey();
	}
	void PushFront(T k) {
		shared_ptr<DNode<T>> new_node = make_shared<DNode<T>>(k);
		size++;
		if (head == nullptr) {
			head = tail = new_node;
			return;
		}
		head->SetPrev(new_node);
		new_node->SetNext(head);
		head = new_node;
	}
	void PushBack(T k) {
		shared_ptr<DNode<T>> new_node = make_shared<DNode<T>>(k);
		size++;
		if (head == nullptr) {
			head = tail = new_node;
			return;
		}
		tail->SetNext(new_node);
		new_node->SetPrev(tail);
		tail = new_node;
	}
	T PopFront() {
		assert(head);
		T val = head->GetKey();
		size--;
		if (head == tail) {
			head = tail = nullptr;
			return val;
		}
		head->GetNext()->SetPrev(nullptr);
		head = head->GetNext();
		return val;
	}
	T PopBack() {
		assert(head);
		T val = tail->GetKey();
		size--;
		if (head == tail) {
			head = tail = nullptr;
			return val;
		}
		tail->GetPrev()->SetNext(nullptr);
		tail = tail->GetPrev();
		return val;
	}
	void Insert(int pos, T k) {
		assert(pos >= 0 && pos <= size);
		if (pos == 0) {
			PushFront(k);
			return;
		}
		if (pos == size) {
			PushBack(k);
			return;
		}
		shared_ptr<DNode<T>> new_node = make_shared<DNode<T>>(k);
		auto p = FindByIndex(pos);
		p->GetPrev()->SetNext(new_node);
		new_node->SetPrev(p->GetPrev());
		new_node->SetNext(p);
		p->SetPrev(new_node);
		size++;
	}
	T Erase(int pos) {
		assert(pos >= 0 && pos < size);
		if (pos == 0) return PopFront();
		if (pos == size - 1) return PopBack();
		auto p = FindByIndex(pos);
		p->GetPrev()->SetNext(p->GetNext());
		p->GetNext()->SetPrev(p->GetPrev());
		size--;
		return p->GetKey();
	}
	void Remove(T k) {
		int pos = FindIndex(k);
		while (pos >= 0) {
			Erase(pos);
			pos = FindIndex(k);
		}
	}
	T ValueNFromEnd(int n) {
		return ValueAt(size - n - 1);
	}

	void Reverse() {
		if (head == nullptr) return;
		shared_ptr<DNode<T>> prev = nullptr;
		auto curr = head;
		while (curr) {
			auto next = curr->GetNext();
			curr->SetNext(prev);
			if (prev) prev->SetPrev(curr);
			prev = curr;
			curr = next;
		}
		head = tail;
		tail = prev;
	}
private:
	shared_ptr<DNode<T>> head;
	shared_ptr<DNode<T>> tail;
	int FindIndex(T k) {
		auto p = head;
		int pos = 0;
		while (p != nullptr) {
			if (p->GetKey() == k) return pos;
			p = p->GetNext();
			pos++;
		}
		return -1;
	}
	shared_ptr<DNode<T>> FindByIndex(int pos) {
		auto p = head;
		while (pos--) p = p->GetNext();
		return p;
	}
	int size;
};