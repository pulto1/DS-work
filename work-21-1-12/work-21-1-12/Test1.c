#define _CRT_SECURE_NO_WARNINGS

//���������ÿ���ڵ㶼������ͬ��ֵ����ô�ö��������ǵ�ֵ��������
//
//ֻ�и��������ǵ�ֵ������ʱ���ŷ��� true�����򷵻� false��

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