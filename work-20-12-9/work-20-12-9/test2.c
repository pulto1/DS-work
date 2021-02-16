//#define _CRT_SECURE_NO_WARNINGS
//
////将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
////
////示例 1：
////
////输入：l1 = [1, 2, 4], l2 = [1, 3, 4]
////输出：[1, 1, 2, 3, 4, 4]
//
///**
//* Definition for singly-linked list.
//* struct ListNode {
//*     int val;
//*     struct ListNode *next;
//* };
//*/
//
//
//struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
//{
//	if (l1 == NULL)
//		return l2;
//
//	if (l2 == NULL)
//		return l1;
//
//	struct ListNode* head = NULL;
//	struct ListNode* tail = NULL;
//
//	if (l1->val < l2->val)
//	{
//		head = l1;
//		tail = l1;
//		l1 = l1->next;
//	}
//
//	else
//	{
//		head = l2;
//		tail = l2;
//		l2 = l2->next;
//	}
//
//	while (l1 && l2)
//	{
//		if (l1->val < l2->val)
//		{
//			tail->next = l1;
//			tail = l1;
//			l1 = l1->next;
//		}
//
//		else
//		{
//			tail->next = l2;
//			tail = l2;
//			l2 = l2->next;
//		}
//	}
//
//	if (l1)
//	{
//		tail->next = l1;
//	}
//
//	if (l2)
//	{
//		tail->next = l2;
//	}
//
//	return head;
//}