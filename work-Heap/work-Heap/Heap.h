#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

//向下调整算法
void AdjustDown(Heap* php, int n, HPDataType root);

// 堆的构建
void HeapCreate(Heap* php, HPDataType* a, int n);
// 堆的销毁
void HeapDestory(Heap* php);
// 堆的插入
void HeapPush(Heap* php, HPDataType x);
// 堆的删除
void HeapPop(Heap* php);
// 取堆顶的数据
HPDataType HeapTop(Heap* php);
// 堆的数据个数
int HeapSize(Heap* php);
// 堆的判空
int HeapEmpty(Heap* php);

// 对数组进行堆排序
void HeapSort(int* a, int n);

// TopK问题：找出N个数里面最大/最小的前K个问题。
// 比如：未央区排名前10的泡馍，西安交通大学王者荣耀排名前10的韩信，全国排名前10的李白。等等问题都是Topk问题，
// 需要注意：
// 找最大的前K个，建立K个数的小堆
// 找最小的前K个，建立K个数的大堆
void PrintTopK(int* a, int n, int k);
void TestTopk();