#define _CRT_SECURE_NO_WARNINGS

//����һ�����飬�������е�Ԫ�������ƶ� k ��λ�ã����� k �ǷǸ�����

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