#define _CRT_SECURE_NO_WARNINGS

//����һ���������飬����Ҫ�� ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�
//��Ҫʹ�ö��������ռ䣬������� ԭ�� �޸��������� ����ʹ�� O(1) ����ռ����������ɡ�

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
	for (i = 1; i < numsSize; i++)//�ӵڶ���Ԫ�ؿ�ʼ�ж�
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
