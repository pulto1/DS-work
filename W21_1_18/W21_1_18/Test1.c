#define _CRT_SECURE_NO_WARNINGS

//��һ�����򣬶����û������һ����������ַ��������ݴ��ַ�������һ������������ָ�뷽ʽ�洢���� 
//�������µ���������ַ����� ABC##DE#G##F### ���С�#����ʾ���ǿո񣬿ո��ַ����������
//������˶������Ժ��ٶԶ������������������������������

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
}BTNode;

BTNode* CreatBinaryTree(char* arr, int* i)
{
	if (arr[*i] == '#')
	{
		(*i)++;
		return NULL;
	}

	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->val = arr[*i];
	(*i)++;

	root->left = CreatBinaryTree(arr, i);
	root->right = CreatBinaryTree(arr, i);

	return root;
}

void InOrder(BTNode* root)
{
	if (root == NULL)
		return;

	InOrder(root->left);
	printf("%c ", root->val);
	InOrder(root->right);
}

int main()
{
	char arr[100];
	scanf("%s", arr);

	int i = 0;
	BTNode* root = CreatBinaryTree(arr, &i);
	InOrder(root);
	return 0;
}