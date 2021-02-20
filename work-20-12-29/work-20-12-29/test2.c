#define _CRT_SECURE_NO_WARNINGS

//��������в�������
//
//���������㷨��
//���������ǵ����ģ�ÿ��ֻ�ƶ�һ��Ԫ�أ�ֱ������Ԫ�ؿ����γ�һ�����������б�
//ÿ�ε����У���������ֻ�������������Ƴ�һ���������Ԫ�أ��ҵ������������ʵ���λ�ã���������롣
//�ظ�ֱ�������������ݲ�����Ϊֹ��
//
//ʾ�� 1��
//���� : 4->2->1->3
//��� : 1->2->3->4

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

struct ListNode* insertionSortList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;

	struct ListNode* sortHead = head;

	struct ListNode* curList = head->next;
	sortHead->next = NULL;

	while (curList)
	{

		if (curList->val <= sortHead->val)
		{
			struct ListNode* ret = curList;
			curList = curList->next;
			ret->next = sortHead;
			sortHead = ret;
		}

		else
		{
			struct ListNode* prev = sortHead;
			struct ListNode* curSort = sortHead;
			while (curList->val > curSort->val)
			{

				prev = curSort;
				curSort = curSort->next;
				if (curSort == NULL)
					break;
			}

			if (curSort)
			{
				struct ListNode* ret = curList;
				curList = curList->next;
				prev->next = ret;
				ret->next = curSort;
			}

			else
			{
				struct ListNode* ret = curList;
				curList = curList->next;
				prev->next = ret;
				ret->next = NULL;
			}
		}
	}

	return sortHead;
}