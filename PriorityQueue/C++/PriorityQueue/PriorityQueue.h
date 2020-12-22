#pragma once 
#include <vector>
#include <assert.h>
using namespace std;

/*
	In this max-heap implementation: 
		index starts with 0 instead of 1 in other imlementations
		use vector as array to store values
	Calculate parent-children relationship:
		parent(i) = (i-1)/2;
		left_child(i) = 2*i+1;
		right_child(i) = 2*i+2;
	Number of nodes that have children = n/2-1 with n is total number of nodes
*/

template<typename T>
class PriorityQueue {
public:
	PriorityQueue() {
		size = 0;
	}

	~PriorityQueue() {}

	int GetSize() {
		return size;
	}

	bool IsEmpty() {
		return size == 0;
	}

	void Insert(T new_val) {
		// Insert to the end of array to maintain Complete Binary Tree structure 
		arr.push_back(new_val);
		SiftUp(size++);
	}
	
	T Remove(int pos) {
		assert(pos >= 0 && pos < size);
		T val = arr[pos];
		arr[pos] = INT_MAX; // !!! This only works with data type int
		SiftUp(pos);
		ExtractMax();
		return val;
	}

	T ExtractMax() {
		// Replace with the right-most leaf node to maintain Complete Binary Tree structure 
		assert(!IsEmpty());
		swap(arr[size-1], arr[0]);
		size--;
		SiftDown(0);
		return arr[size];
	}
	
	T GetMax() {
		assert(!IsEmpty());
		return arr[0];
	}

	
	void Heapsort(vector<T>& target) {
		BuildHeap(target);
		for (int i = 0; i < arr.size()-1; i++) {
			swap(arr[size-1], arr[0]);
			size--;
			SiftDown(0);
		}
		for (int i = 0; i < arr.size(); i++)
			target[i] = arr[i];
	}
private:
	int size;
	vector<T> arr;
	
	void SiftUp(int i) {
		if (!i) return;
		int parent = (i - 1) / 2;
		if (arr[parent] < arr[i]) {
			swap(arr[parent], arr[i]);
			SiftUp(parent);
		}
	}
	
	void SiftDown(int i) {
		// get the child with the largest value
		int maxInx = i;
		int l = i * 2 + 1;
		int r = i * 2 + 2;
		if (l < size && arr[l] > arr[maxInx]) maxInx = l;
		if (r < size && arr[r] > arr[maxInx]) maxInx = r;
		if (i != maxInx) {
			swap(arr[i], arr[maxInx]);
			SiftDown(maxInx);
		}
	}
	
	void BuildHeap(vector<T> & target) {
		arr = target;
		size = target.size();
		for (int i = size / 2 - 1; i >= 0; i--)
			SiftDown(i);
	}
};