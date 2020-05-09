#include<iostream>
using namespace std;
#include<vector>

class Node {
public:
	int val;
	Node* left;
	Node* right;

	Node() {}

	Node(int _val) {
		val = _val;
		left = NULL;
		right = NULL;
	}

	Node(int _val, Node* _left, Node* _right) {
	val = _val;
	left = _left;
	right = _right;
	}
};

class Solution {
public:
	vector<Node*> arr;
	void push(Node* root)
	{
		if (root == nullptr)
			return;
		push(root->left);
		arr.push_back(root);
		push(root->right);
	}
	Node* treeToDoublyList(Node* root) {

		if (root == nullptr)
			return NULL;
		push(root);
		for (int i = 0; i<arr.size() - 1; i++)
		{
			arr[i]->right = arr[i + 1];
			arr[i + 1]->left = arr[i];
		}
		arr[0]->left = arr[arr.size() - 1];
		arr[arr.size() - 1]->right = arr[0];
		return arr[0];

	}
};