#define _CRT_SECURE_NO_WARNINGS

#include "Heap.h"

static void Swap(HPDataType* x, HPDataType* y)
{
	HPDataType tmp = *x;
	*x = *y;
	*y = tmp;
}

//向下调整法建大堆
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
//向上调整算法，建大堆
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

// 堆的构建
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

// 堆的插入
void HeapPush(Heap* php, HPDataType x)
{
	assert(php);

	if (php->_capacity == php->_size)
	{
		php->_capacity *= 2;
		HPDataType* tmp = (HPDataType*)realloc(php->_a, sizeof(HPDataType)* php->_capacity);
		//判断是否开辟成功
		//...
		php->_a = tmp;
	}

	php->_a[php->_size] = x;
	php->_size++;
	AdjustUp(php, php->_size, php->_size - 1);
}

// 堆的删除
void HeapPop(Heap* php)
{
	assert(php);
	assert(php->_size != 0);

	Swap(&php->_a[0], &php->_a[php->_size - 1]);
	php->_size--;
	AdjustDown(php, php->_size, 0);
}

// 取堆顶的数据
HPDataType HeapTop(Heap* php)
{
	assert(php);
	assert(php->_size != 0);

	return php->_a[0];
}

// 堆的数据个数
int HeapSize(Heap* php)
{
	assert(php);

	return php->_size;
}

// 堆的判空
int HeapEmpty(Heap* php)
{
	assert(php);

	return php->_size == 0 ? 1 : 0;
}

// 堆的销毁
void HeapDestory(Heap* php)
{
	assert(php);

	free(php->_a);
	php->_a = NULL;
}

// 对数组进行堆排序
void HeapSort(int* a, int n)
{
	assert(a);

	//1.建堆
	Heap hp;
	hp._a = a;
	hp._size = hp._capacity = n;

	int i = 0;
	for (i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(&hp, n, i);
	}

	//2.排序
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
	//1.建大小为n的大堆
	Heap hp;
	HeapCreate(&hp, a, n);

	//找最大的前k个数
	while (k)
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
		k--;
	}
	HeapDestory(&hp);
}