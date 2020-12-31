#include <iostream>
#include "Stack.h"
using namespace std;
int main() {
	Stack<int> s;
	s.Push(2);
	s.Push(1);
	s.Push(5);
	cout << s.Pop() << endl;
	cout << s.Pop() << endl;
	cout << s.Pop() << endl;
	return 0;
}