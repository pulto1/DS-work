//#define _CRT_SECURE_NO_WARNINGS
//
////����һ����������������е�����k����㡣
////
////ʾ��1
////����
////1, { 1, 2, 3, 4, 5 }
////
////����ֵ
////{ 5 }
//
///**
//* struct ListNode {
//*	int val;
//*	struct ListNode *next;
//* };
//*/
//
///**
//*
//* @param pListHead ListNode��
//* @param k int����
//* @return ListNode��
//*/
//struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
//{
//	struct ListNode* fast = pListHead;
//	struct ListNode* slow = pListHead;
//
//	while (k--)
//	{
//		if (fast == NULL)
//			return NULL;
//		fast = fast->next;
//	}
//
//	while (fast)
//	{
//		fast = fast->next;
//		slow = slow->next;
//	}
//
//	return slow;
//}