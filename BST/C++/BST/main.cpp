#include "BNode.h"
#include "BST.h"
#include<iostream>
using namespace std;

int main() {
	BST<int> bst;
	bst.Insert(2);
	bst.Insert(1);
	bst.Insert(4);
	bst.Insert(5);
	bst.Insert(3);
	bst.Insert(6);
	//bst.Delete(4);
	cout << bst.Search(4) << endl;
	cout << bst.Search(3) << endl;
	//bst.GetInorder();
	auto inorder = bst.GetLevelorder();
	for (auto num : inorder) cout << num << " ";
	return 0;
}
