#include <iostream>
#include "Queue.h"
using namespace std;
int main() {
	Queue<int> queue;
	queue.Push(1);
	queue.Push(3);
	queue.Push(2);
	cout << queue.Pop()<< endl;
	cout << queue.Pop() << endl;
	cout << queue.Pop() << endl;
	return 0;
}