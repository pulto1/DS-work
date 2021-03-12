#define _CRT_SECURE_NO_WARNINGS

//给定一个二叉树，判断它是否是高度平衡的二叉树。
//
//本题中，一棵高度平衡二叉树定义为：
//
//一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。


/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

bool _isBalanced(struct TreeNode* root, int* Depth)
{
	if (root == NULL)
		return true;

	int leftDepth = 0;
	if (_isBalanced(root->left, &leftDepth) == false)
	{
		return false;
	}

	int rightDepth = 0;
	if (_isBalanced(root->right, &rightDepth) == false)
	{
		return false;
	}


	if (abs(rightDepth - leftDepth) > 1)
		return false;

	*Depth = leftDepth > rightDepth ? 1 + leftDepth : 1 + rightDepth;

	return true;
}

bool isBalanced(struct TreeNode* root)
{
	int Depth = 0;

	return _isBalanced(root, &Depth);
}