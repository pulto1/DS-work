#define _CRT_SECURE_NO_WARNINGS

//反转一个单链表。
//
//示例 :
//输入 : 1->2->3->4->5->NULL
//输出 : 5->4->3->2->1->NULL
//
// 进阶 :
//你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL)
	{
		return NULL;
	}


	struct ListNode* n1 = NULL;
	struct ListNode* n2 = head;
	struct ListNode* n3 = head->next;

	while (n2 != NULL)
	{
		n2->next = n1;

		n1 = n2;
		n2 = n3;

		if (n3 != NULL)
			n3 = n3->next;
	}
	return n1;
}