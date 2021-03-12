#define _CRT_SECURE_NO_WARNINGS

//����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������
//
//�����У�һ�ø߶�ƽ�����������Ϊ��
//
//һ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������ 1 ��


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