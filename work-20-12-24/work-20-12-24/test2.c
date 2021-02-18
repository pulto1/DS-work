#define _CRT_SECURE_NO_WARNINGS

//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
//为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 
//如果 pos 是 - 1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。
//
//说明：不允许修改给定的链表。
//
//进阶：
//你是否可以使用 O(1) 空间解决此题？

//方法1
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode *detectCycle(struct ListNode *head)
{
	struct ListNode *fast = head;
	struct ListNode *slow = head;

	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow)
			break;
	}

	if (fast == NULL || fast->next == NULL)
		return NULL;

	struct ListNode *meet = fast;
	while (meet != head)
	{
		head = head->next;
		meet = meet->next;
	}

	return meet;

}

//方法2
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode *detectCycle(struct ListNode *head)
{
	struct ListNode *fast = head;
	struct ListNode *slow = head;

	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow)
			break;
	}

	if (fast == NULL || fast->next == NULL)
		return NULL;

	struct ListNode *meetHead = fast->next;
	fast->next = NULL;

	fast = head;
	slow = meetHead;

	struct ListNode *curHead = head;
	int la = 0;
	while (curHead)
	{
		la++;
		curHead = curHead->next;
	}

	struct ListNode *curMeetHead = meetHead;
	int lb = 0;
	while (curMeetHead)
	{
		lb++;
		curMeetHead = curMeetHead->next;
	}

	if (la < lb)
	{
		fast = meetHead;
		slow = head;
	}

	int gap = abs(la - lb);

	while (gap--)
	{
		fast = fast->next;
	}

	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}

	return fast;
}