#define _CRT_SECURE_NO_WARNINGS

//对链表进行插入排序。
//
//插入排序算法：
//插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
//每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
//重复直到所有输入数据插入完为止。
//
//示例 1：
//输入 : 4->2->1->3
//输出 : 1->2->3->4

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