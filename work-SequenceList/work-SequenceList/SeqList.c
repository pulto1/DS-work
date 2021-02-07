#define _CRT_SECURE_NO_WARNINGS

#include"SeqList.h"

//顺序表的初始化
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

//顺序表的销毁
void SeqListDestory(SeqList* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

//顺序表的打印
void SeqListPrint(SeqList* ps)
{
	size_t i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//顺序表的查容
static void SeqListCheckCapacity(SeqList* ps)
{
	if (ps->size == ps->capacity)
	{
		ps->capacity *= 2;
		SLDateType* ret = (SLDateType*)realloc(ps->a, sizeof(SLDateType)*ps->capacity);
		if (ret == NULL)
		{
			perror("扩容失败原因");
		}
		else
		{
			ps->a = ret;
		}
	}
}

//顺序表的尾插
void SeqListPushBack(SeqList* ps, SLDateType x)
{
	SeqListCheckCapacity(ps);

	ps->a[ps->size] = x;
	ps->size++;
}

//顺序表的前插
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

//顺序表的前删
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

//顺序表的后删
void SeqListPopBack(SeqList* ps)
{
	ps->size--;
}

// 顺序表的查找
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

// 顺序表在pos位置插入x
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

// 顺序表删除pos位置的值
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
