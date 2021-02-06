#define _CRT_SECURE_NO_WARNINGS

//数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？

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
