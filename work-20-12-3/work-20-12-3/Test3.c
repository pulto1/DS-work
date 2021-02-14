#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdlib.h>

//对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。例如，如果 X = 1231，那么其数组形式为 [1, 2, 3, 1]。
//给定非负整数 X 的数组形式 A，返回整数 X + K 的数组形式。

//示例 1：
//
//输入：A = [1, 2, 0, 0], K = 34
//输出：[1, 2, 3, 4]
//解释：1200 + 34 = 1234

int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
{
	int ret = 0;
	int tmp = K;
	while (tmp)//计算K的位数
	{
		tmp /= 10;
		ret++;
	}
	int *p = (int*)malloc(ASize*sizeof(int)); //动态开辟数组A的内存，因为相加之后A的内存大小可能会改变，所以不能用静态
	memcpy(p, A, ASize*sizeof(int));//将原A数组的内容拷贝过去
	int i = ASize - 1; //i的初始位置是数组的最后一位，相当于这串数的个位
	int count = 0; 
	if (ASize < ret)//K大于数组位数
	{
		while (K)//用K的位数控制相加次数
		{
			if (i < 0)//数组位置不够，要创建新的空间
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
			K /= 10;//控制次数

			if (p[i] >= 10)//和下面的介绍一样
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

	else//K小于等于数组组成数字大小
	{
		count = ASize;
		while (count)
		{

			p[i] = K % 10 + p[i];//个位相加
			K /= 10;

			if (p[i] >= 10)//发生进位的情况
			{
				if (i == 0)//在最高位发生进位要进行扩容操作
				{
					i++;
					ASize++;
					p = (int*)realloc(p, ASize*sizeof(int));//多开辟出一块空间
					count++;
					int end = ASize - 1;
					while (end)//将原来的位数往后挪一位
					{
						p[end] = p[end - 1];
						end--;
					}
					p[0] = 0;//将个位空出来
				}
				p[i - 1] += p[i] / 10;//前一位加上后一位的进位
				p[i] %= 10;//后一位只保留个位
			}
			i--;//进入下一位
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
