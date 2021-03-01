#define _CRT_SECURE_NO_WARNINGS

#include "Stack.h"

int isValid(char * s)
{
	Stack st;
	StackInit(&st);
	int ret = 1;

	while (*s)
	{
		if (*s == '(' || *s == '[' || *s == '{')
		{
			StackPush(&st, *s);
			s++;
		}

		else
		{
			if (*s == ')' && StackTop(&st) != '(')
			{
				ret = 0;
				break;
			}

			if (*s == ']' && StackTop(&st) != '[')
			{
				ret = 0;
				break;
			}

			if (*s == '}' && StackTop(&st) != '{')
			{
				ret = 0;
				break;
			}

			StackPop(&st);
			s++;
		}
	}

	if (*s == '\0')
		ret = 1;

	return ret;
}

//void Test()
//{
//	Stack st;
//	StackInit(&st);
//	StackPush(&st, 1);
//	StackPush(&st, 2);
//	StackPush(&st, 3);
//	printf("%d ", StackTop(&st));
//	StackPop(&st);
//	printf("%d ", StackTop(&st));
//	StackPop(&st);
//	StackPush(&st, 4);
//	StackPush(&st, 5);
//
//	while (!StackEmpty(&st))
//	{
//		printf("%d ", StackTop(&st));
//		StackPop(&st);
//	}
//
//	printf("\n");
//	StackDestroy(&st);
//}

int main()
{
	char arr[] = "()";
	isValid(arr);
	return 0;
}