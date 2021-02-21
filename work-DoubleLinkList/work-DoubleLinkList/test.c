#define _CRT_SECURE_NO_WARNINGS

#include "DoubleLinkList.h"

void Test()
{
	ListNode* pHead = ListCreate();

	ListPushBack(pHead, 1);
	ListPushBack(pHead, 2);
	ListPushBack(pHead, 3);
	ListPushBack(pHead, 4);
	ListPushBack(pHead, 5);
	ListPrint(pHead);
	ListDestory(pHead);

	//ListNode* pos = ListFind(pHead, 3);
	//ListErase(pos);
	//ListPrint(pHead);

	//ListInsert(pos, 100);
	//ListPrint(pHead);

	//pos->data = 100;
	//ListPrint(pHead);

	/*ListPopFront(pHead);
	ListPrint(pHead);
	ListPopFront(pHead);
	ListPrint(pHead);
	ListPopFront(pHead);
	ListPrint(pHead);*/

	//ListPushFront(pHead, -1);
	//ListPrint(pHead);
	//ListPushFront(pHead, -2);
	//ListPrint(pHead);
	//ListPushFront(pHead, -3);
	//ListPrint(pHead);
	//ListPushBack(pHead, 4);
	//ListPushBack(pHead, 5);


	//ListPopBack(pHead);
	//ListPrint(pHead);
	//ListPopBack(pHead);
	//ListPrint(pHead);



	/*ListPushBack(pHead, 2);
	ListPrint(pHead);
	ListPushBack(pHead, 3);
	ListPrint(pHead);*/


}

int main()
{
	Test();
	return 0;
}