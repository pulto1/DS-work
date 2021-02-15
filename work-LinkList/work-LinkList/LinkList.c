#define _CRT_SECURE_NO_WARNINGS

#include"LinkList.h"


// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* NewNode = (SListNode*)malloc(sizeof(SListNode));
	if (NewNode == NULL)
	{
		printf("申请结点失败\n");
		exit(-1);
	}
	NewNode->data = x;
	NewNode->next = NULL;
	return NewNode;
}

// 单链表打印
void SListPrint(SListNode* plist)
{
	while (plist != NULL)
	{
		printf("%d->", plist->data);
		plist = plist->next;
	}

	printf("NULL\n");
}

// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);

	if (*pplist == NULL)
	{
		*pplist = newnode;
	}

	else
	{
		SListNode* tail = *pplist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newnode;
	}
}

// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}

// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	if (*pplist == NULL)
	{
		return;
	}

	else if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;	
	}

	else
	{
		SListNode* prev = NULL;
		SListNode* tail = *pplist;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
	}
}

// 单链表头删
void SListPopFront(SListNode** pplist)
{
	if (*pplist == NULL)
	{
		return;
	}

	else
	{
		SListNode* prev = *pplist;
		*pplist = (*pplist)->next;
		free(prev);
	}
	
}

// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	SListNode* cur = plist;

	while (cur != NULL)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}

	return NULL;
}

// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos)
{
	assert(pos);

	if (pos->next != NULL)
	{
		SListNode* next = pos->next;
		pos->next = next->next;
		free(next);	
	}
}

// 单链表的销毁
void SListDestory(SListNode** plist)
{
	if (*plist == NULL)
	{
		return;
	}

	
	SListNode* cur = *plist;
	SListNode* del = *plist;
	cur = cur->next;
	while (cur != NULL)
	{
		free(del);
		del = cur;
		cur = cur->next;
	}
	free(del);
	*plist = NULL;
}