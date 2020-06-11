#include<vector>
#include<algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void pushnode(vector<int>& v, TreeNode* root)
	{
		if (root == nullptr)
			return;
		v.push_back(root->val);
		if (root->left)
			pushnode(v, root->left);
		if (root->right)
			pushnode(v, root->right);
	}
	int kthLargest(TreeNode* root, int k) {
		vector<int> v;
		pushnode(v, root);
		sort(v.begin(), v.end());
		return v[v.size() - k];

	}
};