#define _CRT_SECURE_NO_WARNINGS

//给定一个二叉树，检查它是否是镜像对称的。

bool _isSymmetric(struct TreeNode* left, struct TreeNode* right)
{
	if (left == NULL && right == NULL)
		return true;
	if (left == NULL || right == NULL)
		return false;
	return left->val == right->val
		&& _isSymmetric(left->left, right->right)
		&& _isSymmetric(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root){
	if (root == NULL)
		return true;
	return _isSymmetric(root->left, root->right);
}