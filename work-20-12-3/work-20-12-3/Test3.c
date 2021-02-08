#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdlib.h>

int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
{
	int ret = 0;
	int tmp = K;
	while (tmp)
	{
		tmp /= 10;
		ret++;
	}
	int *p = (int*)malloc(ASize*sizeof(int));
	memcpy(p, A, ASize*sizeof(int));
	int i = ASize - 1;
	int count = 0;
	if (ASize < ret)
	{
		while (K)
		{
			if (i < 0)
			{
				i++;
				ASize++;
				p = (int*)realloc(p, ASize*sizeof(int));
				int end = ASize - 1;
				while (end)
				{
					p[end] = p[end - 1];
					end--;
				}
				p[0] = 0;
			}
			p[i] = K % 10 + p[i];
			K /= 10;

			if (p[i] >= 10)
			{
				if (i == 0)
				{
					i++;
					ASize++;
					p = (int*)realloc(p, ASize*sizeof(int));
					int end = ASize - 1;
					while (end)
					{
						p[end] = p[end - 1];
						end--;
					}
					p[0] = 0;
				}
				p[i - 1] += p[i] / 10;
				p[i] %= 10;
			}
			i--;
		}
	}

	else
	{
		count = ASize;
		while (count)
		{

			p[i] = K % 10 + p[i];
			K /= 10;

			if (p[i] >= 10)
			{
				if (i == 0)
				{
					i++;
					ASize++;
					p = (int*)realloc(p, ASize*sizeof(int));
					count++;
					int end = ASize - 1;
					while (end)
					{
						p[end] = p[end - 1];
						end--;
					}
					p[0] = 0;
				}
				p[i - 1] += p[i] / 10;
				p[i] %= 10;
			}
			i--;
			count--;
		}
	}
	*returnSize = ASize;
	return p;
}


int main()
{
	int arr[] = { 0 };
	int k =23;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int p = 0;
	addToArrayForm(arr, sz, k, &p);
}
