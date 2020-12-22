#include "PriorityQueue.h"
#include <iostream>
using namespace std;
int main() {
	PriorityQueue<int> pq;
	pq.Insert(2);
	pq.Insert(5);
	pq.Insert(3);
	pq.Insert(4);
	pq.Insert(6);
	cout << pq.ExtractMax() << endl;
	cout << pq.ExtractMax() << endl;
	cout << pq.Remove(1) << endl;
	cout << pq.ExtractMax() << endl;
	cout << pq.ExtractMax() << endl;
	cout << pq.GetSize() << endl;
	vector<int> A{ 1, 2, 4, 2, 5, 2 };
	pq.Heapsort(A);
	for (auto a : A)
		cout << a << " ";
	return 0;
}
