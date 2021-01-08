#pragma once
template <typename T>
class BNode
{
public:

	BNode() {
		left = right = nullptr;
	};

	BNode(T new_val) {
		val = new_val;
		left = right = nullptr;
	}

	~BNode() {
		delete left;
		delete right;
	}

	BNode<T>* GetLeft() { 
		return left; 
	};

	BNode<T>* GetRight() {
		return right;
	}

	T GetVal() {
		return val;
	}
    
	void SetLeft(BNode<T>* node) {
		left = node;
	}
	void SetRight(BNode<T>* node) {
		right = node;
	}
	void SetVal(T new_val) {
		val = new_val;
	}

private:
	T val;
	BNode<T>* left;
	BNode<T>* right;
};



