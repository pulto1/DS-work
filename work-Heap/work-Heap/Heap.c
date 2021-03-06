#define _CRT_SECURE_NO_WARNINGS

#include "Heap.h"

static void Swap(HPDataType* x, HPDataType* y)
{
	HPDataType tmp = *x;
	*x = *y;
	*y = tmp;
}

//���µ����������
void AdjustDown(Heap* php, int n, HPDataType root)
{
	HPDataType parent = root;
	HPDataType child = (parent * 2) + 1;

	while (child < n)
	{
		if (child + 1 < n && php->_a[child] < php->_a[child + 1])
		{
			child++;
		}

		if (php->_a[parent] < php->_a[child])
		{
			Swap(&php->_a[parent], &php->_a[child]);
			parent = child;
			child = parent * 2 + 1;
		}

		else
		{
			break;
		}
	}
}
//���ϵ����㷨�������
void AdjustUp(Heap* php, int n, HPDataType child)
{
	assert(php);

	HPDataType parent = (child - 1) / 2;

	while (child > 0)
	{
		if (php->_a[parent] < php->_a[child])
		{
			Swap(&php->_a[parent], &php->_a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}

		else
		{
			break;
		}
	}
}

// �ѵĹ���
void HeapCreate(Heap* php, HPDataType* a, int n)
{
	assert(php);

	php->_a = (HPDataType*)malloc(sizeof(HPDataType)* n);
	php->_size = php->_capacity = n;
	memcpy(php->_a, a, sizeof(a)* n);

	int i = 0;
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(php, n, i);
	}
}

// �ѵĲ���
void HeapPush(Heap* php, HPDataType x)
{
	assert(php);

	if (php->_capacity == php->_size)
	{
		php->_capacity *= 2;
		HPDataType* tmp = (HPDataType*)realloc(php->_a, sizeof(HPDataType)* php->_capacity);
		//�ж��Ƿ񿪱ٳɹ�
		//...
		php->_a = tmp;
	}

	php->_a[php->_size] = x;
	php->_size++;
	AdjustUp(php, php->_size, php->_size - 1);
}

// �ѵ�ɾ��
void HeapPop(Heap* php)
{
	assert(php);
	assert(php->_size != 0);

	Swap(&php->_a[0], &php->_a[php->_size - 1]);
	php->_size--;
	AdjustDown(php, php->_size, 0);
}

// ȡ�Ѷ�������
HPDataType HeapTop(Heap* php)
{
	assert(php);
	assert(php->_size != 0);

	return php->_a[0];
}

// �ѵ����ݸ���
int HeapSize(Heap* php)
{
	assert(php);

	return php->_size;
}

// �ѵ��п�
int HeapEmpty(Heap* php)
{
	assert(php);

	return php->_size == 0 ? 1 : 0;
}

// �ѵ�����
void HeapDestory(Heap* php)
{
	assert(php);

	free(php->_a);
	php->_a = NULL;
}

// ��������ж�����
void HeapSort(int* a, int n)
{
	assert(a);

	//1.����
	Heap hp;
	hp._a = a;
	hp._size = hp._capacity = n;

	int i = 0;
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(&hp, n, i);
	}

	//2.����
	int end = hp._size - 1;
	
	while (end > 0)
	{
		Swap(&hp._a[0], &hp._a[end]);
		end--;
		AdjustDown(&hp, end + 1, 0);
	}
}

void PrintTopK(int* a, int n, int k)
{
	//1.����СΪn�Ĵ��
	Heap hp;
	HeapCreate(&hp, a, n);

	//������ǰk����
	while (k)
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
		k--;
	}
	HeapDestory(&hp);
}