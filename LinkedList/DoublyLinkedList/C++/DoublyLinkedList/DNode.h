#pragma once
#include <memory>
using namespace std;

template <typename T>
class DNode {
public:
	DNode() {
		prev = next = nullptr;
	}
	DNode(T k) {
		key = k;
		prev = next = nullptr;
	}
	~DNode() = default;
	T GetKey() {
		return key;
	}
	shared_ptr<DNode<T>> GetPrev() {
		return prev;
	}
	shared_ptr<DNode<T>> GetNext() {
		return next;
	}
	void SetPrev(shared_ptr<DNode<T>> p) {
		prev = p;
	}
	void SetNext(shared_ptr<DNode<T>> n) {
		next = n;
	}

private:
	T key;
	shared_ptr<DNode<T>> prev;
	shared_ptr<DNode<T>> next;
};