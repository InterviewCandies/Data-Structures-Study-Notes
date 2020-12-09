#include "BNode.h"
#include "BST.h"
#include<iostream>
using namespace std;

int main() {
	BST<int> bst;
	bst.Insert(3);
	bst.Insert(1);
	bst.Insert(2);
	bst.Insert(4);
	bst.Insert(5);
	bst.Insert(2);
	auto inorder = bst.GetLevelorder();
	for (auto num : inorder) cout << num << " ";
	return 0;
}
