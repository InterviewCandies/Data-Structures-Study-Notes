#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;
int main() {
	DoublyLinkedList<int> list;
	//2 5 1 3 4 3
	// 3 4 3 1 5 2  
	list.PushBack(4);
	list.PushFront(1);
	list.PushFront(2);
	list.PushBack(3);
	list.Insert(2, 3);
	list.Insert(1, 5);
	list.Reverse();
	//list.Remove(3);
	//cout << list.Erase(3)<< endl;
	cout << list.ValueAt(3) << endl;
	cout << list.ValueNFromEnd(3) << endl;
	cout << list.Search(8) << endl;
	cout << list.GetSize() << endl;
	return 0;
}