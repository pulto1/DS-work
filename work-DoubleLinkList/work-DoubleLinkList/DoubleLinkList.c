#define _CRT_SECURE_NO_WARNINGS

#include "DoubleLinkList.h"

//申请新结点
ListNode* BuyNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));

	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	
	return newnode;
}

// 创建返回链表的头结点.
ListNode* ListCreate()
{
	ListNode* phead = BuyNode(0);
	
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

// 双向链表打印
void ListPrint(ListNode* pHead)
{
	assert(pHead);

	ListNode* cur = pHead->next;

	while (cur != pHead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}

	printf("\n");
}

// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);

	ListNode* newnode = BuyNode(x);

	ListNode* tail = pHead->prev;

	tail->next = newnode;
	newnode->prev = tail;

	pHead->prev = newnode;
	newnode->next = pHead;
}

// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	assert(pHead->next != pHead);

	ListNode* tail = pHead->prev;
	ListNode* tailPrev = tail->prev;

	tailPrev->next = pHead;
	pHead->prev = tailPrev;

	free(tail);
}

// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);

	ListNode* newnode = BuyNode(x);

	ListNode* first = pHead->next;

	pHead->next = newnode;
	newnode->prev = pHead;

	first->prev = newnode;
	newnode->next = first;
}

// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	assert(pHead->next != pHead);

	ListNode* first = pHead->next;
	ListNode* second = first->next;

	pHead->next = second;
	second->prev = pHead;

	free(first);
}

// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);

	ListNode* pos = pHead->next;

	while (pos != pHead)
	{
		if (pos->data == x)
			return pos;

		pos = pos->next;
	}

	return NULL;
}

// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);

	ListNode* newnode = BuyNode(x);

	ListNode* posPrev = pos->prev;

	posPrev->next = newnode;
	newnode->prev = posPrev;

	newnode->next = pos;
	pos->prev = newnode;
}

// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);

	assert(pos->next != pos);

	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;

	posPrev->next = posNext;
	posNext->prev = posPrev;

	free(pos);
}

// 双向链表销毁
void ListDestory(ListNode* pHead)
{
	assert(pHead);

	ListNode* del = pHead->next;

	while (del != pHead)
	{
		ListNode* next = del->next;

		free(del);

		del = next;
	}
	
	pHead->next = pHead;
	pHead->prev = pHead;
}
