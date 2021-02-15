#define _CRT_SECURE_NO_WARNINGS

//给定一个头结点为 head 的非空单链表，返回链表的中间结点。
//
//如果有两个中间结点，则返回第二个中间结点。
//
//示例 1：
//
//输入：[1, 2, 3, 4, 5]
//输出：此列表中的结点 3 (序列化形式：[3, 4, 5])
//返回的结点值为 3 。(测评系统对该结点序列化表述是[3, 4, 5])。
//注意，我们返回了一个 ListNode 类型的对象 ans，这样：
//ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, 以及 ans.next.next.next = NULL.

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


struct ListNode* middleNode(struct ListNode* head)
{
	int count = 0;
	struct ListNode* ret = head;
	while (ret != NULL)
	{
		count++;
		ret = ret->next;
	}

	if (count % 2 == 0)
		count = count / 2 + 1;

	else
		count = (1 + count) / 2;

	struct ListNode* ans = head;
	while (--count)
	{
		ans = ans->next;
	}

	return ans;

}
