#define _CRT_SECURE_NO_WARNINGS

//һ���������� nums �����������֮�⣬�������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�Ҫ��ʱ�临�Ӷ���O(n)���ռ临�Ӷ���O(1)��

/**
* Note: The returned array must be malloced, assume caller calls free().
*/

int* singleNumbers(int* nums, int numsSize, int* returnSize)
{
	int ret = 0;
	int i = 0;
	for (i = 0; i < numsSize; i++)
	{
		ret ^= nums[i];
	}

	for (i = 0; i < numsSize; i++)
	{
		if (((ret >> i) & 1) == 1)
			break;
	}

	int pos = i;
	int num1 = 0;
	for (i = 0; i < numsSize; i++)
	{
		if (((nums[i] >> pos) & 1) == 1)
			num1 ^= nums[i];
	}
	int num2 = ret ^ num1;
	int* p = (int*)malloc(2 * sizeof(int));
	*returnSize = 2;
	*p = num1;
	*(p + 1) = num2;
	return p;
}