TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	if (preorder.size() == 0)
		return nullptr;
	if (preorder.size() == 1)
	{
		TreeNode* root = new TreeNode(preorder[0]);
		return root;
	}
	TreeNode* root = new TreeNode(preorder[0]);
	auto it = inorder.begin();
	while (*it != preorder[0])
		it++;

	int leftlong = it - inorder.begin();
	vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + 1 + leftlong);
	vector<int> left_inorder(inorder.begin(), it);

	vector<int> right_preorder(preorder.begin() + leftlong + 1, preorder.end());
	vector<int> right_inorder(it + 1, inorder.end());

	root->left = buildTree(left_preorder, left_inorder);
	root->right = buildTree(right_preorder, right_inorder);

	return root;
}