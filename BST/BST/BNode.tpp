#include "BNode.h"
template<typename T>
BNode<T> ::BNode() : left(nullptr), right(nullptr), val{ 0 } {}

template<typename T>
BNode<T>* BNode<T> ::GetLeft() {
	return left;
}

template <typename T>
BNode<T>* BNode<T> ::GetRight() {
	return right;
}

template<typename T>
T BNode<T> ::GetVal() {
	return val;
}

template<typename T>
void BNode<T> ::SetLeft(BNode<T>* node) {
	left = node;
}

template<typename T>
void BNode<T> ::SetRight(BNode<T>* node) {
	right = node;
}

template<typename T>
void BNode<T> ::SetVal(T new_val) {
	val = new_val;
}


template <typename T>
BNode<T> :: ~BNode() {
	delete left;
	delete right;
}