#pragma once
#include <vector>
using namespace std;
class UnionFind {
public:
	UnionFind(int N) {
		root.assign(N, 0);
		rank.assign(N, 0);
		size.assign(N, 0);
		for (int i = 0; i < N; i++)
			root[i] = i;
	}
	~UnionFind() = default;
	int GetRoot(int x) {
		if (root[x] == x) return x;
		root[x] = GetRoot(root[x]);
		return root[x];
	}
	bool SameUnion(int u, int v) {
		u = GetRoot(u);
		v = GetRoot(v);
		return u == v;
	}
	bool UnionByRank(int u, int v) {
		u = GetRoot(u);
		v = GetRoot(v);
		if (u == v) return false;
		if (rank[u] < rank[v])
			root[u] = v;
		else if (rank[v] < rank[u])
			root[v] = u;
		else root[u] = v, rank[v]++;
		return true;
	}
	bool UnionBySize(int u, int v) {
		u = GetRoot(u);
		v = GetRoot(v);
		if (u == v) return false;
		if (size[u] < size[v])
			root[u] = v, size[v] += size[u];
		else root[v] = u, size[u] += size[v];
	}
private:
	vector<int> root;
	vector<int> rank;
	vector<int> size;
};