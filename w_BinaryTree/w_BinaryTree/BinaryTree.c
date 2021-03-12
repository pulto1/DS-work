#define _CRT_SECURE_NO_WARNINGS

#include "BinaryTree.h"
#include "Queue.h"

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
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

// ����������
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

// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->_left == NULL && root->_right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;

	if (k == 1)
		return 1;

	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

// ����������ֵΪx�Ľڵ�
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

// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return;

	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

// �������������
void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
		return;
	
	BinaryTreePrevOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_right);
}

// �������������
void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
		return;

	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
	printf("%c ", root->_data);
}

// �������
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

// �ж϶������Ƿ�����ȫ������
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