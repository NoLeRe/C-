bool flag = false;
void dfs(TreeNode* root, int sum)
{
	if (!root)
		return;
	sum -= root->val;
	if (!root->left&&!root->right&&sum == 0)
		flag = true;
	dfs(root->left, sum);
	dfs(root->right, sum);
}
bool hasPathSum(TreeNode* root, int sum) {
	dfs(root, sum);
	return flag;
}