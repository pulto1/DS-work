#define _CRT_SECURE_NO_WARNINGS

//����nums������0��n������������������ȱ��һ�������д�����ҳ��Ǹ�ȱʧ�����������а취��O(n)ʱ���������

int missingNumber(int* nums, int numsSize)
{
	int num1 = 0;
	int num2 = 0;
	int i = 0;
	for (i = 0; i < numsSize + 1; i++)
	{
		num1 += i;
	}

	for (i = 0; i < numsSize; i++)
	{
		num2 += nums[i];
	}

	return num1 - num2;
}
