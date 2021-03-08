#define _CRT_SECURE_NO_WARNINGS

//·­×ªÒ»¿Ã¶þ²æÊ÷¡£

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


struct TreeNode* invertTree(struct TreeNode* root)
{
	if (root == NULL)
		return NULL;

	struct TreeNode* left = invertTree(root->left);
	struct TreeNode* right = invertTree(root->right);

	if (left == NULL && right == NULL)
		return root;

	if (left == NULL)
	{
		left = right;
		right = NULL;
		root->left = left;
		root->right = right;
		return root;
	}

	if (right == NULL)
	{
		right = left;
		left = NULL;
		root->left = left;
		root->right = right;
		return root;
	}

	struct TreeNode* tmp = right;
	right = left;
	left = tmp;
	root->left = left;
	root->right = right;

	return root;

}