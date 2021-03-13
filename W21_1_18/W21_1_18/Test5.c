#define _CRT_SECURE_NO_WARNINGS

//给定一个二叉树的根节点 root ，返回它的 中序 遍历。

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


/**
* Note: The returned array must be malloced, assume caller calls free().
*/

int TreeSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;

	return 1 + TreeSize(root->left) + TreeSize(root->right);
}

void _inorderTraversal(struct TreeNode* root, int* arr, int* i)
{
	if (root == NULL)
		return;


	_inorderTraversal(root->left, arr, i);

	arr[*i] = root->val;
	(*i)++;

	_inorderTraversal(root->right, arr, i);

	return;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
	*returnSize = TreeSize(root);
	if (*returnSize == 0)
		return NULL;

	int* TreeArr = (int*)malloc(sizeof(int)* (*returnSize));

	int i = 0;
	_inorderTraversal(root, TreeArr, &i);

	return TreeArr;
}