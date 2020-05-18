#include<iostream>
using namespace std;
#include<vector>
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> v;
	vector<int> ret;

	void DFS(TreeNode* root, int sum)
	{
		if (root == nullptr)
			return;
		sum -= root->val;
		ret.push_back(root->val);
		if (!root->left&&!root->right&&sum == 0)
			v.push_back(ret);
		DFS(root->left, sum);
		DFS(root->right, sum);
		ret.pop_back();
	}

	vector<vector<int>> pathSum(TreeNode* root, int sum) {

		DFS(root, sum);
		return v;
	}
};