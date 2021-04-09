#define _CRT_SECURE_NO_WARNINGS

#include "Sort.h"
#include "Stack.h"

// 插入排序
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}

			else
			{
				break;
			}
		}

		a[end + 1] = tmp;
	}
}

// 希尔排序
void ShellSort(int* a, int n)
{
	int gap = n;

	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];

			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}

				else
				{
					break;
				}
			}

			a[end + gap] = tmp;
		}
	}
}

void Swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

// 选择排序
void SelectSort(int* a, int n)
{
	
	int begin = 0;
	int end = n - 1;
	
	while (begin < end)
	{
		int maxi = begin;
		int mini = begin;
		for (int i = begin; i < end + 1; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}

			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}

		Swap(&a[mini], &a[begin]);
		if (maxi == begin)
			maxi = mini;

		Swap(&a[maxi], &a[end]);

		begin++;
		end--;
	}
}

// 堆排序
void AdjustDwon(int* a, int n, int root)
{
	//排升序建大堆
	int parent = root;
	int child = root * 2 + 1;

	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			child++;
		}

		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}

		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)
{
	//1.建堆
	
	for (int i = (n - 1) / 2 - 1; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}

	//2.排序
	for (int j = n - 1; j > 0; j--)
	{
		Swap(&a[0], &a[j]);
		AdjustDwon(a, j, 0);
	}
}

// 冒泡排序
void BubbleSort(int* a, int n)
{
	for (int i = 1; i < n ; i++) //i控制的是趟数，n个数共进行(1->n-1)次排序
	{
		int flag = 0;
		for (int j = 0; j < n - i; j++) //j控制的是每次比较的前一个元素，从0 -> n-i
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				flag = 1;
			}
		}

		if (flag == 0)
			break;
	}
}

// 快速排序递归实现

int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) / 2;

	if (a[left] < a[right])
	{
		if (a[mid] < a[left])
			mid = left;

		else if (a[mid] > a[right])
			mid = right;
	}

	else
	{
		if (a[mid] > a[left])
			mid = left;

		else if (a[mid] < a[right])
			mid = right;
	}

	return mid;
}

// 快速排序hoare版本
int PartSort1(int* a, int left, int right)
{
	int mid = GetMidIndex(a, left, right);
	Swap(&a[mid], &a[right]);

	int keyindex = right;

	while (left < right)
	{
		while (left < right && a[left] <= a[keyindex])
		{
			left++;
		}

		while (left < right && a[right] >= a[keyindex])
		{
			right--;
		}

		Swap(&a[left], &a[right]);
	}

	Swap(&a[left], &a[keyindex]);

	return left;
}

// 快速排序挖坑法
int PartSort2(int* a, int left, int right)
{
	int key = a[right];

	while (left < right)
	{
		while (left < right && a[left] <= key)
		{
			left++;
		}

		a[right] = a[left];

		while (left < right && a[right] >= key)
		{
			right--;
		}

		a[left] = a[right];
	}

	a[left] = key;
	return left;
}

// 快速排序前后指针法
int PartSort3(int* a, int left, int right)
{
	int key = a[right];

	int cur = left;
	int prev = left - 1;

	while (cur < right)
	{
		if (a[cur] < key && ++prev != cur)
		{
			Swap(&a[cur], &a[prev]);
		}

		cur++;
	}

	Swap(&a[++prev], &a[right]);
	
	return prev;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	if ((right - left + 1) <= 10)
	{
		InsertSort(a, right - left + 1);
	}

	else
	{
		int div = PartSort3(a, left, right);

		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}	
}

// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right)
{
	Stack st;
	StackInit(&st);

	StackPush(&st, right);
	StackPush(&st, left);

	while (!StackEmpty(&st))
	{
		int begin = StackTop(&st);
		StackPop(&st);

		int end = StackTop(&st);
		StackPop(&st);

		int div = PartSort1(a, begin, end);

		if (div + 1 < end)
		{
			StackPush(&st, end);
			StackPush(&st, div + 1);
		}

		if (begin < div - 1)
		{
			StackPush(&st, div - 1);
			StackPush(&st, begin);
		}								
	}

	StackDestroy(&st);
}

void MergeArr(int* a, int left1, int right1, int left2, int right2, int* tmp)
{
	int left = left1;
	int right = right2;
	int i = left1;
	while (left1 <= right1 && left2 <= right2)
	{
		if (a[left1] < a[left2])
		{
			tmp[i] = a[left1];
			i++;
			left1++;
		}

		else
		{
			tmp[i] = a[left2];
			i++;
			left2++;
		}
	}

	while (left1 <= right1)
	{
		tmp[i] = a[left1];
		i++;
		left1++;
	}

	while (left2 <= right2)
	{
		tmp[i] = a[left2];
		i++;
		left2++;
	}

	while (left <= right)
	{
		a[left] = tmp[left];
		left++;
	}
}

void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;

	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	MergeArr(a, left, mid, mid + 1, right, tmp);

}

// 归并排序递归实现
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);

	_MergeSort(a, 0, n - 1, tmp);

	free(tmp);
	tmp = NULL;
}

// 归并排序非递归实现
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	int gap = 1;

	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int left1 = i;
			int right1 = i + gap - 1;
			int left2 = i + gap;
			int right2 = i + 2 * gap - 1;

			if (left2 > n - 1)
				break;

			if (right2 > n - 1)
				right2 = n - 1;

			MergeArr(a, left1, right1, left2, right2, tmp);
		}
		gap *= 2;
	}
	
	free(tmp);
	tmp = NULL;
}

// 计数排序
void CountSort(int* a, int n) 
{
	int min = a[0];
	int max = a[0];

	int i = 1;
	while (i < n)
	{
		if (a[i] < min)
		{
			min = a[i];
		}

		if (a[i] > max)
		{
			max = a[i];
		}

		i++;
	}

	int range = max - min + 1;

	int* countArr = (int*)malloc(sizeof(int) * range);

	memset(countArr, 0, sizeof(int) * range);
	i = 0;
	while (i < n)
	{
		countArr[a[i++] - min]++;
	}

	int index = 0;
	i = 0;
	while (i < range)
	{
		while (countArr[i]--)
		{
			a[index++] = i + min;
		}
		i++;
	}
}