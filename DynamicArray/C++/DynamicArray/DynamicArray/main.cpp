#pragma once
#include "DynamicArray.h"
#include <iostream>
using namespace std;
int main() {
	DynamicArray<int> arr;
	arr.PushBack(2);
	arr.PushBack(1);
	arr.PushBack(3);
	arr.PushBack(5);
	arr.PushBack(1);
	/*arr.Insert(1, 5);
	arr.Insert(3, 7);
	arr.Remove(2);*/
	arr.Reverse();
	arr.Print();
	cout << arr.Get(1);
	return 0;
}