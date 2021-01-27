#include<iostream>
#include "UnionFind.h"
using namespace std;
int main() {
	UnionFind uf(10);
	uf.UnionByRank(3, 7);
	uf.UnionByRank(1, 5);
	uf.UnionByRank(1, 3);
	cout << uf.SameUnion(1, 2) << endl;
	cout << uf.SameUnion(1, 7) << endl;
	cout << uf.SameUnion(2, 3) << endl;
	cout << uf.SameUnion(3, 5) << endl;
	return 0;
}