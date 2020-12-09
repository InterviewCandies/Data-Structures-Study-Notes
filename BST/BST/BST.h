#pragma once
#include "BNode.h"
#include <vector>
#include <queue>
using namespace std;

template<typename T>
class BST
{
public: 
	BST() {
		root = nullptr;
	}

	~BST() {
		while (!root) root = DeleteHelper(root, root->GetVal());
	}
	// Check if target is in BST 
	bool Search(T target) {
		if (SearchHelper(root, target)) return true;
		return false;
	}
	// Insert new value into BST
	void Insert(T new_val) {
		root = InsertHelper(root, new_val);
	}
	// Remove a target from BST
	bool Delete(T target) {
		if (!Search(target)) return false;
		root = DeleteHelper(root, target);
		return true;
	}
	// Check if a tree is a BST 
	static bool IsBST(BNode<T>* root) {
		return IsBSTHelper(root, INT_MIN, INT_MAX);
	}
	// Get current height of BST
	int GetHeight() {
		return GetHeightHelper(root);
	}

	vector<T> GetInorder() {
		vector<T> inorder;
		InorderTraversal(root, inorder);
		return inorder;
	}
	vector<T> GetPreorder() {
		vector<T> preorder;
		PreorderTraversal(root, preorder);
		return preorder;
	}
	vector<T> GetPostorder() {
		vector<T> postorder;
		PostorderTraversal(root, postorder);
		return postorder;
	}
	vector<T> GetLevelorder() {
		vector<T> levelorder;
		LevelorderTraversal(root, levelorder);
		return levelorder;
	}

private:
	BNode<T>* root;

	BNode<T>* SearchHelper(BNode<T>* root, T target) {
		if (root == nullptr) return nullptr;
		if (root->GetVal() == target) return root;
		if (root->GetVal() < target) return SearchHelper(root->GetRight(), target);
		return SearchHelper(root->GetLeft(), target);
	}

	BNode<T>* InsertHelper(BNode<T>* root, T new_val) {
		if (root == nullptr) return new BNode<T>(new_val);
		if (root->GetVal() == new_val) return root;
		if (root->GetVal() > new_val) root->SetLeft(InsertHelper(root->GetLeft(), new_val));
		else root->SetRight(InsertHelper(root->GetRight(), new_val));
		return root;
	}

	int GetHeightHelper(BNode<T>* root) {
		if (root == nullptr) return 0;
		return max(GetHeightHelper(root->GetLeft()), GetHeightHelper(root->GetRight())) + 1;
	}

	void InorderTraversal(BNode<T> * root, vector<T> & inorder) {
		if (!root) return;
		InorderTraversal(root->GetLeft(), inorder);
		inorder.push_back(root->GetVal());
		InorderTraversal(root->GetRight(), inorder);
	}

	void PreorderTraversal(BNode<T>* root, vector<T>& preorder) {
		if (!root) return;
		preorder.push_back(root->GetVal());
		PreorderTraversal(root->GetLeft(), preorder);
		PreorderTraversal(root->GetRight(), preorder);
	}

	void PostorderTraversal(BNode<T>* root, vector<T>& postorder) {
		if (!root) return;
		PostorderTraversal(root->GetLeft(), postorder);
		PostorderTraversal(root->GetRight(), postorder);
		postorder.push_back(root->GetVal());
	}

	void LevelorderTraversal(BNode<T>* root, vector<T>& levelorder) {
		queue<BNode<T> *> q;
		if (root == nullptr) return;
		q.push(root);
		while (!q.empty()) {
			auto curr = q.front();
			q.pop();
			levelorder.push_back(curr->GetVal());
			if (curr->GetLeft()) q.push(curr->GetLeft());
			if (curr->GetRight()) q.push(curr->GetRight());
		}
	}

	static bool IsBSTHelper(BNode<T>* root, int minVal, int maxVal) {
		if (root == nullptr) return true;
		if (minVal <= root->GetVal() && root->GetVal() <= maxVal)
			return IsBSTHelper(root->GetLeft(), minVal, root->GetVal()) && IsBSTHelper(root->GetRight(), root->GetVal(), maxVal);
		return false;
	}

	BNode<T>* FindSuccessor(BNode<T>* root) {
		if (!root->GetLeft()) return root;
		return FindSuccessor(root->GetLeft());
	}

	BNode<T>* DeleteHelper(BNode<T>* root, T target) {
		if (root->GetVal() < target) root->SetRight(DeleteHelper(root->GetRight(), target));
		if (root->GetVal() > target) root->SetLeft(DeleteHelper(root->GetLeft(), target));
		if (root->GetVal() == target) {
			// case 1: target is leaf node
			if (!root->GetLeft() && !root->GetRight()) {
				delete root;
				return nullptr;
			}
			// case 2a: target has one left child
			else if (!root->GetRight()) {
				auto temp = root;
				root = root->GetLeft();
				delete temp;
			}
			// case 2b: target has one right child
			else if (!root->GetLeft()) {
				auto temp = root;
				root = root->GetRight();
				delete temp;
			}
			// case 3: target has two children
			else {
				auto successor = FindSuccessor(root->GetRight());
				root->SetVal(successor->GetVal());
				successor->SetVal(target);
				root->SetRight(DeleteHelper(successor, target));
			}
		}
		return root;
	}
};

