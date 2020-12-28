#include <iostream>
#include "SinglyLinkedList.h"
using namespace std;

int main() {
	SinglyLinkedList<int> list;
	//3 1 3 2 5
	list.PushFront(1);
	list.PushBack(2); 
	list.PushFront(3);
	list.PushBack(5);
	list.Insert(2, 3);
	list.Reverse();
	cout << list.Search(1) << endl;
	cout << list.Search(7) << endl;
	cout << list.ValueAt(0) << endl;
	cout << list.ValueAt(1) << endl;
	cout << list.ValueNFromEnd(1) << endl;
	cout << list.Erase(1) << endl;
	cout << list.GetSize() << endl;
	return 0;
}