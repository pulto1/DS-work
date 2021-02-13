//#define _CRT_SECURE_NO_WARNINGS

/*给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。
初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。你可以假设 nums1 的空间大小等于 m + n，这样它就有足够的空间保存来自 nums2 的元素*/


//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
//{
//	int i = m;
//	int j = 0;
//	for (i = m; i < m + n; i++)
//	{
//		nums1[i] = nums2[j];
//		j++;
//	}
//
//
//	for (i = 0; i < m + n - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < m + n -1 - i; j++)
//		{
//			if (nums1[j] > nums1[j + 1])
//			{
//				int tmp = nums1[j + 1];
//				nums1[j + 1] = nums1[j];
//				nums1[j] = tmp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int arr1[] = { 1, 2, 3, 0, 0, 0 };
//	int arr2[] = { 2, 5, 6 };
//	merge(arr1, 6, 3, arr2, 3, 3);
//	return 0;
//}