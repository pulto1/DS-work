#define _CRT_SECURE_NO_WARNINGS

#include"LinkList.h"


// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* NewNode = (SListNode*)malloc(sizeof(SListNode));
	if (NewNode == NULL)
	{
		printf("������ʧ��\n");
		exit(-1);
	}
	NewNode->data = x;
	NewNode->next = NULL;
	return NewNode;
}

// �������ӡ
void SListPrint(SListNode* plist)
{
	while (plist != NULL)
	{
		printf("%d->", plist->data);
		plist = plist->next;
	}

	printf("NULL\n");
}

// ������β��
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

// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}

// �������βɾ
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

// ������ͷɾ
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

// ���������
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

// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* newnode = BuySListNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
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

// �����������
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