#define _CRT_SECURE_NO_WARNINGS

//给定一个二叉树，返回它的 后序 遍历。

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

void _postorderTraversal(struct TreeNode* root, int* arr, int* i)
{
	if (root == NULL)
	{
		return;
	}

	else
	{
		_postorderTraversal(root->left, arr, i);
		_postorderTraversal(root->right, arr, i);

		arr[*i] = root->val;
		(*i)++;
		return;
	}
}


int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
	*returnSize = TreeSize(root);
	if (*returnSize == 0)
		return NULL;

	int* TreeArr = (int*)malloc(sizeof(int)* (*returnSize));

	int i = 0;
	_postorderTraversal(root, TreeArr, &i);

	return TreeArr;
}