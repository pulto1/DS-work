#define _CRT_SECURE_NO_WARNINGS

#include "LinkList.h"

void Test()
{
	SListNode * head = NULL;

	SListPushBack(&head, 1);
	SListPushBack(&head, 2);
	SListPushBack(&head, 3);
	SListPushBack(&head, 4);
	SListPushBack(&head, 5);
	SListPrint(head);
	SListNode *p = SListFind(head, 2);
	SListEraseAfter(p);
	SListPrint(head);
	SListDestory(&head);
	SListPrint(head);

	/*SListInsertAfter(p, 0);
	SListPrint(head);*/

	//SListPopBack(&head);
	//SListPrint(head);
	//SListPopFront(&head);
	//SListPrint(head);


	//SListPushBack(&head, 4);
	//SListPrint(head);
	//SListPushBack(&head, 5);
	//SListPrint(head);

	//SListPushFront(&head, -1);
	//SListPrint(head);
	//SListPushFront(&head, -2);
	//SListPushFront(&head, -3);
	//SListPushFront(&head, -4);
	//SListPrint(head);
	//SListPopBack(&head);
	//SListPrint(head);



}

int main()
{
	Test();
}