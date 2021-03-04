#define _CRT_SECURE_NO_WARNINGS

//请你仅使用两个栈实现先入先出队列。队列应当支持一般队列的支持的所有操作（push、pop、peek、empty）：
//
//实现 MyQueue 类：
//
//void push(int x) 将元素 x 推到队列的末尾
//int pop() 从队列的开头移除并返回元素
//int peek() 返回队列开头的元素
//boolean empty() 如果队列为空，返回 true ；否则，返回 false

// 支持动态增长的栈
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;		// 栈顶
	int _capacity;  // 容量 
}Stack;

// 初始化栈 
void StackInit(Stack* ps)
{
	assert(ps);

	ps->_a = (STDataType*)malloc(4 * sizeof(STDataType));
	ps->_capacity = 4;
	ps->_top = 0;
}

// 入栈 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);

	if (ps->_capacity == ps->_top)
	{
		ps->_capacity *= 2;
		STDataType* ret = (STDataType*)realloc(ps->_a, ps->_capacity * sizeof(STDataType));
		if (ret == NULL)
		{
			free(ps);
			ps = NULL;
			exit(-1);
		}

		else
		{
			ps->_a = ret;
		}
	}

	ps->_a[ps->_top] = data;
	ps->_top++;
}

// 出栈 
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->_top != 0);

	ps->_top--;
}

// 获取栈顶元素 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->_top != 0);

	return ps->_a[ps->_top - 1];
}

// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	assert(ps);

	return ps->_top;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->_top == 0 ? 1 : 0;
}

// 销毁栈 
void StackDestroy(Stack* ps)
{
	free(ps->_a);
	ps->_a = NULL;
}


typedef struct
{
	Stack _pushST;
	Stack _popST;
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate()
{
	MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&q->_popST);
	StackInit(&q->_pushST);

	return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x)
{
	StackPush(&obj->_pushST, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj)
{
	int ret = myQueuePeek(obj);
	StackPop(&obj->_popST);

	return ret;
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj)
{
	if (!StackEmpty(&obj->_popST))
		return StackTop(&obj->_popST);

	while (!StackEmpty(&obj->_pushST))
	{
		StackPush(&obj->_popST, StackTop(&obj->_pushST));
		StackPop(&obj->_pushST);
	}

	return StackTop(&obj->_popST);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj)
{
	return StackEmpty(&obj->_pushST) && StackEmpty(&obj->_popST);
}

void myQueueFree(MyQueue* obj)
{
	StackDestroy(&obj->_popST);
	StackDestroy(&obj->_pushST);

	free(obj);
}