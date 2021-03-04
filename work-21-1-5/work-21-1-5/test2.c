#define _CRT_SECURE_NO_WARNINGS

//�����ʹ������ջʵ�������ȳ����С�����Ӧ��֧��һ����е�֧�ֵ����в�����push��pop��peek��empty����
//
//ʵ�� MyQueue �ࣺ
//
//void push(int x) ��Ԫ�� x �Ƶ����е�ĩβ
//int pop() �Ӷ��еĿ�ͷ�Ƴ�������Ԫ��
//int peek() ���ض��п�ͷ��Ԫ��
//boolean empty() �������Ϊ�գ����� true �����򣬷��� false

// ֧�ֶ�̬������ջ
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;		// ջ��
	int _capacity;  // ���� 
}Stack;

// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	assert(ps);

	ps->_a = (STDataType*)malloc(4 * sizeof(STDataType));
	ps->_capacity = 4;
	ps->_top = 0;
}

// ��ջ 
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

// ��ջ 
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->_top != 0);

	ps->_top--;
}

// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->_top != 0);

	return ps->_a[ps->_top - 1];
}

// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	assert(ps);

	return ps->_top;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->_top == 0 ? 1 : 0;
}

// ����ջ 
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