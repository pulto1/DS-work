#define _CRT_SECURE_NO_WARNINGS

//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

//void rotate(int* nums, int numsSize, int k)
//{
//	if (k > numsSize)
//	{
//		k = k - numsSize;
//	}
//
//	int left = 0;
//	int right = numsSize - k - 1;
//	int tmp = 0;
//	while (left < right)
//	{
//		tmp = nums[left];
//		nums[left] = nums[right];
//		nums[right] = tmp;
//		left++;
//		right--;
//	}
//
//	left = numsSize - k;
//	right = numsSize - 1;
//	while (left < right)
//	{
//		tmp = nums[left];
//		nums[left] = nums[right];
//		nums[right] = tmp;
//		left++;
//		right--;
//	}
//
//	left = 0;
//	right = numsSize - 1;
//	while (left < right)
//	{
//		tmp = nums[left];
//		nums[left] = nums[right];
//		nums[right] = tmp;
//		left++;
//		right--;
//	}
//}