#define _CRT_SECURE_NO_WARNINGS

#include "Heap.h"

void Test()
{
	int a[] = { 1, 5, 3, 8, 7, 6 };
	PrintTopK(a, sizeof(a) / sizeof(int), 3);
	HeapSort(a, sizeof(a) / sizeof(int));
	Heap hp;
	HeapCreate(&hp, a, sizeof(a) / sizeof(int));
	HeapPush(&hp, 9);
	HeapPop(&hp);
	HeapDestory(&hp);
}

int main()
{
	Test();
	return 0;
}