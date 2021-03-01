#define _CRT_SECURE_NO_WARNINGS

//请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通队列的全部四种操作（push、top、pop 和 empty）。
//
//实现 MyStack 类：
//
//void push(int x) 将元素 x 压入栈顶。
//int pop() 移除并返回栈顶元素。
//int top() 返回栈顶元素。
//boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
//
//
//注意：
//
//你只能使用队列的基本操作 —— 也就是 push to back、peek / pop from front、size 和 is empty 这些操作。
//你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
// 链式结构：表示队列

typedef int QDataType;

typedef struct QListNode
{
	QDataType _data;
	struct QListNode* _next;
}QNode;

// 队列的结构 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;

// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);

	q->_front = NULL;
	q->_rear = NULL;
}

// 队尾入队列 
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

// 队头出队列 
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

// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(q->_front);

	return q->_front->_data;
}

// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(q->_front);

	return q->_rear->_data;
}

// 获取队列中有效元素个数 
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

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);

	return q->_front == NULL ? 1 : 0;
}

// 销毁队列 
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

typedef struct
{
	Queue _qe1;
	Queue _qe2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate()
{
	MyStack* st = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&st->_qe1);
	QueueInit(&st->_qe2);

	return st;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x)
{
	if (!QueueEmpty(&obj->_qe1))
	{
		QueuePush(&obj->_qe1, x);
	}

	else
	{
		QueuePush(&obj->_qe2, x);
	}
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj)
{
	int ret = 0;

	if (!QueueEmpty(&obj->_qe1))
	{
		QNode* cur = (&obj->_qe1)->_front;

		while (cur->_next)
		{
			QueuePush((&obj->_qe2), QueueFront(&obj->_qe1));
			QNode* next = cur->_next;
			QueuePop(&obj->_qe1);
			cur = next;
		}

		ret = cur->_data;
		QueuePop(&obj->_qe1);
	}

	else
	{
		QNode* cur = (&obj->_qe2)->_front;

		while (cur->_next)
		{
			QueuePush((&obj->_qe1), QueueFront(&obj->_qe2));
			QNode* next = cur->_next;
			QueuePop(&obj->_qe2);
			cur = next;
		}

		ret = cur->_data;
		QueuePop(&obj->_qe2);
	}

	return ret;
}

/** Get the top element. */
int myStackTop(MyStack* obj)
{
	if (!QueueEmpty(&obj->_qe1))
	{
		return QueueBack(&obj->_qe1);
	}

	else
	{
		return QueueBack(&obj->_qe2);
	}
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj)
{
	if (!QueueEmpty(&obj->_qe1) || !QueueEmpty(&obj->_qe2))
	{
		return false;
	}

	else
	{
		return true;
	}

}

void myStackFree(MyStack* obj)
{
	QueueDestroy(&obj->_qe1);
	QueueDestroy(&obj->_qe2);
}