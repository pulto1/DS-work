#define _CRT_SECURE_NO_WARNINGS

//编一个程序，读入用户输入的一串先序遍历字符串，根据此字符串建立一个二叉树（以指针方式存储）。 
//例如如下的先序遍历字符串： ABC##DE#G##F### 其中“#”表示的是空格，空格字符代表空树。
//建立起此二叉树以后，再对二叉树进行中序遍历，输出遍历结果。

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