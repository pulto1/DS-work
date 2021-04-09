#define _CRT_SECURE_NO_WARNINGS

#include "Sort.h"

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}

	printf("\n");
}

void InsertSortTest()
{
	int arr[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
}

void ShellSortTest()
{
	int arr[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	ShellSort(arr, sizeof(arr) / sizeof(arr[0]));
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
}

void SelectSortTest()
{
	int arr[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	SelectSort(arr, sizeof(arr) / sizeof(arr[0]));
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
}

void HeapSortTest()
{
	int arr[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
}

void BubbleSortTest()
{
	//int arr[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	int arr[] = { 9, 8, 7, 6, 5, 4, 2, 1, 3, 0 };
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	BubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
}

void QuickSortTest()
{
	int arr[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	QuickSort(arr, 0, 9);
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
}

void QuickSortNonRTest()
{
	int arr[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	QuickSortNonR(arr, 0, 9);
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
}

void CountSortTest()
{
	int arr[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	CountSort(arr, 10);
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
}

void MergeSortTest()
{
	int arr[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	MergeSort(arr, 10);
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
}

void MergeSortNonRTest()
{
	int arr[] = { 9, 1, 2, 5, 7, 4, 8, 6, 3, 5 };
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
	MergeSortNonR(arr, 10);
	PrintArray(arr, sizeof(arr) / sizeof(arr[0]));
}

int main()
{
	/*InsertSortTest();*/
	/*ShellSortTest();*/
	/*SelectSortTest();*/
	/*HeapSortTest();*/
	/*BubbleSortTest();*/
	/*QuickSortTest();*/
	/*QuickSortNonRTest();*/
	/*CountSortTest();*/
	/*MergeSortTest();*/
	MergeSortNonRTest();
	return 0;
}