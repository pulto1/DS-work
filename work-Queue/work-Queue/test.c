#define _CRT_SECURE_NO_WARNINGS

#include "Queue.h"

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
			QueuePop(&obj->_qe1);
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
int myStackEmpty(MyStack* obj)
{
	if (!QueueEmpty(&obj->_qe1) || !QueueEmpty(&obj->_qe2))
	{
		return 1;
	}

	else
	{
		return 0;
	}

}

void myStackFree(MyStack* obj)
{
	QueueDestroy(&obj->_qe1);
	QueueDestroy(&obj->_qe2);
}

void Test()
{
    MyStack* st = myStackCreate();
	myStackPush(st, 1);
	myStackPush(st, 2);
	printf("%d \n", myStackTop(st)); // ·µ»Ø 2
	printf("%d \n", myStackPop(st));
	printf("%d \n", myStackEmpty(st));
	myStackFree(st);
}

int main()
{
	Test();
	return 0;
}