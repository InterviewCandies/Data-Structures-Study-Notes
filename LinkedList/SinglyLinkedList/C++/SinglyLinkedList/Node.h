#pragma once
#include <memory>
using namespace std;

template<typename T>
class Node {
public:
	Node() {
		next = nullptr;
		key = 0;
	}
	Node(T k) {
		key = k;
		next = nullptr;
	}

	~Node() = default;

	T GetKey() {
		return key;
	}
	void SetKey(T k) {
		key = k;
	}
	shared_ptr<Node<T>> GetNext() {
		return next;
	}
	void SetNext(shared_ptr<Node<T>> n) {
		next = n;
	}
private:
	T key;
	shared_ptr<Node<T>> next;
};