#define _CRT_SECURE_NO_WARNINGS

#include "BinaryTree.h"

void Test()
{
	char arr[] = "ABD##E#H##CF##G##";

	int i = 0;
	BTNode* root = BinaryTreeCreate(arr, &i);
	printf("BinaryTreeSize:%d\n", BinaryTreeSize(root));
	printf("BinaryTreeLeafSize:%d\n", BinaryTreeLeafSize(root));
	printf("BinaryTreeLevelKSize:%d\n", BinaryTreeLevelKSize(root, 3));
	BinaryTreePrevOrder(root);
	printf("\n");
	BinaryTreeInOrder(root);
	printf("\n");
	BinaryTreePostOrder(root);
	printf("\n");
	BinaryTreeLevelOrder(root);
	printf("\n");
	printf("BinaryTreeComplete:%d\n", BinaryTreeComplete(root));
	
	

	BinaryTreeDestory(&root);
	
}

int main()
{
	Test();
	return 0;
}