#define _CRT_SECURE_NO_WARNINGS

#include "SeqList.h"

void Test()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPrint(&s);
	SeqListInsert(&s, 2, 8);
	SeqListPrint(&s);
	SeqListInsert(&s, 3, 4);
	SeqListPrint(&s);
	SeqListInsert(&s, 3, -1);
	SeqListPrint(&s);
	SeqListErase(&s, 2);
	SeqListPrint(&s);
	SeqListErase(&s, 4);
	SeqListPrint(&s);
	/*int ret = SeqListFind(&s, 6);
	printf("%d\n", ret);*/

}

int main()
{
	Test();
	return 0;
}