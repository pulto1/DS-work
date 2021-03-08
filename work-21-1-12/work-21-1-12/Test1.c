#define _CRT_SECURE_NO_WARNINGS

//如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
//
//只有给定的树是单值二叉树时，才返回 true；否则返回 false。

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

bool isUnivalTree(struct TreeNode* root)
{
	if (root == NULL)
		return true;

	if (root->left == NULL && root->right == NULL)
		return true;

	if (root->left == NULL || root->right == NULL)
	{
		if (root->left == NULL)
		{
			if (root->val == root->right->val)
				return true && isUnivalTree(root->left) && isUnivalTree(root->right);
			else
				return false;
		}

		if (root->right == NULL)
		{
			if (root->val == root->left->val)
				return true && isUnivalTree(root->left) && isUnivalTree(root->right);
			else
				return false;
		}
	}

	if (root->val == root->left->val && root->val == root->right->val)
		return true && isUnivalTree(root->left) && isUnivalTree(root->right);

	else
		return false;
}