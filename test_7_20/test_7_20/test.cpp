vector<vector<int>> ret;
vector<int> path;
void dfs(TreeNode* root, int sum)
{
	if (!root)
		return;
	sum -= root->val;
	path.push_back(root->val);
	if (!root->left&&!root->right&&sum == 0)
	{
		ret.push_back(path);
	}
	dfs(root->left, sum);
	dfs(root->right, sum);
	path.pop_back();
}
vector<vector<int>> pathSum(TreeNode* root, int sum) {
	dfs(root, sum);
	return ret;
}