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

//���µ����㷨
void AdjustDown(Heap* php, int n, HPDataType root);

// �ѵĹ���
void HeapCreate(Heap* php, HPDataType* a, int n);
// �ѵ�����
void HeapDestory(Heap* php);
// �ѵĲ���
void HeapPush(Heap* php, HPDataType x);
// �ѵ�ɾ��
void HeapPop(Heap* php);
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* php);
// �ѵ����ݸ���
int HeapSize(Heap* php);
// �ѵ��п�
int HeapEmpty(Heap* php);

// ��������ж�����
void HeapSort(int* a, int n);

// TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣
// ���磺δ��������ǰ10�����ɣ�������ͨ��ѧ������ҫ����ǰ10�ĺ��ţ�ȫ������ǰ10����ס��ȵ����ⶼ��Topk���⣬
// ��Ҫע�⣺
// ������ǰK��������K������С��
// ����С��ǰK��������K�����Ĵ��
void PrintTopK(int* a, int n, int k);
void TestTopk();