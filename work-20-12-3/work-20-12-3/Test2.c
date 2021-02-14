#define _CRT_SECURE_NO_WARNINGS

//给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
//不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

int removeDuplicates(int* nums, int numsSize)
{
	if (numsSize == 1)
	{
		return 1;
	}
	else if (numsSize == 0)
	{
		return 0;
	}
	int* p1 = nums;
	int* p2 = nums;
	p2++;
	int i = 0;
	int count = 1;
	for (i = 1; i < numsSize; i++)//从第二个元素开始判断
	{
		if (p1[i] != p1[i - 1])
		{
			*p2 = p1[i];
			p2++;
			count++;
		}
	}
	return count;
}
