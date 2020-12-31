#pragma once
#include <assert.h>
#include <vector>
using namespace std;
template<typename T>
class Stack {
public:
	Stack() {
		size = 0;
	}
	~Stack() = default;
	bool IsEmpty() {
		return size == 0;
	}
	T Top() {
		assert(!IsEmpty());
		return arr[size - 1];
	}
	void Push(T data) {
		arr.push_back(data);
		size++;
	}
	T Pop() {
		assert(!IsEmpty());
		T val = arr[size - 1];
		size--;
		arr.pop_back();
		return val;
	}
private:
	vector<int> arr;
	int size;
};