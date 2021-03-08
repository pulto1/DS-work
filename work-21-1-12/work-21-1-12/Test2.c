#define _CRT_SECURE_NO_WARNINGS

//给定一个二叉树，找出其最大深度。
//
//二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
//
//说明 : 叶子节点是指没有子节点的节点。

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


int maxDepth(struct TreeNode* root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL)
	{
		return 1 + maxDepth(root->right);
	}

	if (root->right == NULL)
	{
		return 1 + maxDepth(root->left);
	}

	int ret1 = 1 + maxDepth(root->right);
	int ret2 = 1 + maxDepth(root->left);

	return ret1 >= ret2 ? ret1 : ret2;
}