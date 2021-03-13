#define _CRT_SECURE_NO_WARNINGS

//����������ĸ��ڵ� root ���������ڵ�ֵ�� ǰ�� ������

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

void _preorderTraversal(struct TreeNode* root, int* arr, int* i)
{
	if (root == NULL)
		return;

	arr[*i] = root->val;
	(*i)++;
	_preorderTraversal(root->left, arr, i);
	_preorderTraversal(root->right, arr, i);

	return;
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
	*returnSize = TreeSize(root);
	if (*returnSize == 0)
		return NULL;

	int* TreeArr = (int*)malloc(sizeof(int)* (*returnSize));

	int i = 0;
	_preorderTraversal(root, TreeArr, &i);

	return TreeArr;
}