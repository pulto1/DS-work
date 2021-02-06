#define _CRT_SECURE_NO_WARNINGS

//一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

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