#define _CRT_SECURE_NO_WARNINGS

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize)
{
    int* sortArr = (int*)malloc(sizeof(int) * numsSize);
    memcpy(sortArr, nums, 4 * numsSize);

    int gap = numsSize;

    while (gap > 1)//最后一次以1结束，不用等于1
    {
        gap = gap / 3 + 1;
        for (int i = 0; i < numsSize - gap; i++)
        {
            int end = i;
            int tmp = sortArr[end + gap];
            while (end >= 0)
            {
                if (sortArr[end] > tmp)
                {
                    sortArr[end + gap] = sortArr[end];
                    end -= gap;
                }

                else
                {
                    break;
                }
            }

            sortArr[end + gap] = tmp;//要插入元素放到当前位置往后gap的位置
        }
    }

    *returnSize = numsSize;
    return sortArr;
}