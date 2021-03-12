#define _CRT_SECURE_NO_WARNINGS

#include "BinaryTree.h"
#include "Queue.h"

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	assert(a);
	assert(pi);

	if (a[*pi] == '#')
	{
		(*pi)++;
		return NULL;
	}
		

	BTNode* root = (BTNode*)malloc(sizeof(BTNode));

	root->_data = a[*pi];
	(*pi)++;

	root->_left = BinaryTreeCreate(a, pi);
	root->_right = BinaryTreeCreate(a, pi);

	return root;
}

// 二叉树销毁
void BinaryTreeDestory(BTNode** root)
{

	assert(root);

	if (*root == NULL)
	{
		return;
	}
		

	BTNode* left = (*root)->_left;
	BTNode* right = (*root)->_right;

	free(*root);
	*root = NULL;

	BinaryTreeDestory(&left);
	BinaryTreeDestory(&right);
}

// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}

// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->_left == NULL && root->_right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
		

	if (root->_data == x)
	{
		return root;
	}
		

	BTNode* left = BinaryTreeFind(root->_left, x);
	if (left->_data == x)
	{
		return left;
	}
		

	BTNode* right = BinaryTreeFind(root->_right, x);
	if (right->_data == x)
	{
		return right;
	}
		

	return NULL;
}

// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;

	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	
	BinaryTreePrevOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_right);
}

// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;

	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
	printf("%c ", root->_data);
}

// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
		

	Queue qe;
	QueueInit(&qe);

	QueuePush(&qe, root);

	while (!QueueEmpty(&qe))
	{
		BTNode* front = QueueFront(&qe);
		QueuePop(&qe);
		printf("%c ", front->_data);

		if (front->_left)
			QueuePush(&qe, front->_left);

		if (front->_right)
			QueuePush(&qe, front->_right);
	}

	QueueDestroy(&qe);
}

// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	if (root == NULL)
	{
		return 1;
	}

	Queue qe;
	QueueInit(&qe);

	QueuePush(&qe, root);

	while (!QueueEmpty(&qe))
	{
		BTNode* front = QueueFront(&qe);
		QueuePop(&qe);

		if (front == NULL)
		{
			break;
		}

		QueuePush(&qe, front->_left);
		QueuePush(&qe, front->_right);
	}

	while (!QueueEmpty(&qe))
	{
		if (QueueFront(&qe))
		{
			return 0;
		}
			
		QueuePop(&qe);
	}

	QueueDestroy(&qe);
	return 1;
}