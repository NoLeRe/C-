vector<int> rightSideView(TreeNode* root) {
	vector<int> ret;
	if (!root)
		return ret;
	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty())
	{
		ret.push_back(q.back()->val);
		int sz = q.size();
		for (int i = 0; i<sz; i++)
		{
			TreeNode* node = q.front();
			q.pop();
			if (node->left)
				q.push(node->left);
			if (node->right)
				q.push(node->right);
		}
	}
	return ret;
}