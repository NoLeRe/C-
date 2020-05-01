
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


typedef struct TreeNode TreeNode;
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){

	if (preorderSize == 0)
		return NULL;
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	root->val = preorder[0];
	int index = 0;

	while (index<preorderSize&&preorder[0] != inorder[index])
		index++;

	root->left = buildTree(preorder + 1, index, inorder, index);
	root->right = buildTree(preorder + 1 + index, preorderSize - index - 1, inorder + index + 1, inorderSize - index - 1);

	return root;
}