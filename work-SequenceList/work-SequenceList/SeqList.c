#define _CRT_SECURE_NO_WARNINGS

#include"SeqList.h"

//˳���ĳ�ʼ��
void SeqListInit(SeqList* ps)
{
	ps->a = (SLDateType*) malloc(3 * sizeof(SLDateType));
	if (ps->a == NULL)
	{
		exit(1);
	}
	ps->capacity = 3;
	ps->size = 0;
}

//˳��������
void SeqListDestory(SeqList* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

//˳���Ĵ�ӡ
void SeqListPrint(SeqList* ps)
{
	size_t i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//˳���Ĳ���
static void SeqListCheckCapacity(SeqList* ps)
{
	if (ps->size == ps->capacity)
	{
		ps->capacity *= 2;
		SLDateType* ret = (SLDateType*)realloc(ps->a, sizeof(SLDateType)*ps->capacity);
		if (ret == NULL)
		{
			perror("����ʧ��ԭ��");
		}
		else
		{
			ps->a = ret;
		}
	}
}

//˳����β��
void SeqListPushBack(SeqList* ps, SLDateType x)
{
	SeqListCheckCapacity(ps);

	ps->a[ps->size] = x;
	ps->size++;
}

//˳����ǰ��
void SeqListPushFront(SeqList* ps, SLDateType x)
{
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}

	ps->a[0] = x;
	ps->size++;
}

//˳����ǰɾ
void SeqListPopFront(SeqList* ps)
{
	size_t start = 0;
	while (start < ps->size - 1)
	{
		ps->a[start] = ps->a[start + 1];
		start++;
	}
	ps->size--;
}

//˳���ĺ�ɾ
void SeqListPopBack(SeqList* ps)
{
	ps->size--;
}

// ˳���Ĳ���
int SeqListFind(SeqList* ps, SLDateType x)
{
	size_t i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i + 1;
		}
	}
	return -1;
}

// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	SeqListCheckCapacity(ps);

	size_t end = ps->size - 1;
	while (end >= pos - 1)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos - 1] = x;
	ps->size++;
}

// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, size_t pos)
{
	size_t start = pos - 1;
	while (start <= ps->size - 1)
	{
		ps->a[start] = ps->a[start + 1];
		start++;
	}
	ps->size--;
}
