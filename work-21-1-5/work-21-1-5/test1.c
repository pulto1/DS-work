#define _CRT_SECURE_NO_WARNINGS

//������ѭ������ʵ�֡� ѭ��������һ���������ݽṹ����������ֻ��� FIFO���Ƚ��ȳ���ԭ���Ҷ�β�������ڶ���֮�����γ�һ��ѭ������Ҳ����Ϊ�����λ���������
//
//ѭ�����е�һ���ô������ǿ��������������֮ǰ�ù��Ŀռ䡣��һ����ͨ�����һ��һ���������ˣ����ǾͲ��ܲ�����һ��Ԫ�أ���ʹ�ڶ���ǰ�����пռ䡣����ʹ��ѭ�����У�������ʹ����Щ�ռ�ȥ�洢�µ�ֵ��
//
//���ʵ��Ӧ��֧�����²�����
//
//MyCircularQueue(k) : �����������ö��г���Ϊ k ��
//Front : �Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� - 1 ��
//	Rear : ��ȡ��βԪ�ء��������Ϊ�գ����� - 1 ��
//		   enQueue(value) : ��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻��档
//		   deQueue() : ��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻��档
//		   isEmpty() : ���ѭ�������Ƿ�Ϊ�ա�
//		   isFull() : ���ѭ�������Ƿ�������

typedef struct
{
	int* _a;
	int _front;
	int _rear;
	int _k;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k)
{
	MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	q->_a = (int*)malloc(sizeof(int)* (k + 1));
	q->_front = 0;
	q->_rear = 0;
	q->_k = k;

	return q;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	if (myCircularQueueIsFull(obj))
		return false;

	obj->_a[obj->_rear] = value;
	obj->_rear++;
	obj->_rear %= (obj->_k + 1);

	return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return false;

	obj->_front++;
	obj->_front %= (obj->_k + 1);

	return true;
}

int myCircularQueueFront(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return -1;

	return obj->_a[obj->_front];
}

int myCircularQueueRear(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return -1;

	int tail = obj->_rear - 1;

	if (tail == -1)
		tail = obj->_k;

	return obj->_a[tail];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
	return obj->_front == obj->_rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj)
{
	return (obj->_rear + 1) % (obj->_k + 1) == obj->_front;
}

void myCircularQueueFree(MyCircularQueue* obj)
{
	free(obj->_a);
	free(obj);
}