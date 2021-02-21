#define _CRT_SECURE_NO_WARNINGS

#include "DoubleLinkList.h"

//�����½��
ListNode* BuyNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));

	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	
	return newnode;
}

// �������������ͷ���.
ListNode* ListCreate()
{
	ListNode* phead = BuyNode(0);
	
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

// ˫�������ӡ
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

// ˫������β��
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

// ˫������βɾ
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

// ˫������ͷ��
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

// ˫������ͷɾ
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

// ˫���������
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

// ˫��������pos��ǰ����в���
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

// ˫������ɾ��posλ�õĽڵ�
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

// ˫����������
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
