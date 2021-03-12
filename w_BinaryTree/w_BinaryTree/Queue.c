#define _CRT_SECURE_NO_WARNINGS

#include "Queue.h"

// ��ʼ������ 
void QueueInit(Queue* q)
{
	assert(q);

	q->_front = NULL;
	q->_rear = NULL;
}

// ��β����� 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);

	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	newnode->_data = data;
	newnode->_next = NULL;

	if (q->_front == NULL)
	{
		q->_front = newnode;
		q->_rear = newnode;
	}

	else
	{
		q->_rear->_next = newnode;
		q->_rear = newnode;
	}
}

// ��ͷ������ 
void QueuePop(Queue* q)
{
	assert(q);
	assert(q->_front);

	QNode* next = q->_front->_next;

	free(q->_front);

	q->_front = next;
	if (q->_front == NULL)
		q->_rear = NULL;
}

// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->_front);

	return q->_front->_data;
}

// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->_front);

	return q->_rear->_data;
}

// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	assert(q);

	int count = 0;
	QNode* cur = q->_front;

	while (cur)
	{
		count++;
		cur = cur->_next;
	}

	return count;
}

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	assert(q);

	return q->_front == NULL ? 1 : 0;
}

// ���ٶ��� 
void QueueDestroy(Queue* q)
{
	assert(q);

	QNode* cur = q->_front;
	
	while (cur)
	{
		QNode* next = cur->_next;
		free(cur);
		cur = next;
	}
}