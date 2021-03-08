#define _CRT_SECURE_NO_WARNINGS

//����һ�����������ҳ��������ȡ�
//
//�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����
//
//˵�� : Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣

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