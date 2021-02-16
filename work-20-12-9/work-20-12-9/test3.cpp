////现有一链表的头指针 ListNode* pHead，给一定值x，
////编写一段代码将所有小于x的结点排在其余结点之前，且不能改变原来的数据顺序，返回重新排列后的链表的头指针。
//
///*
//struct ListNode {
//int val;
//struct ListNode *next;
//ListNode(int x) : val(x), next(NULL) {}
//};*/
//class Partition {
//public:
//	ListNode* partition(ListNode* pHead, int x)
//	{
//		struct ListNode* greater = (ListNode*)malloc(sizeof(ListNode));
//		greater->next = NULL;
//		struct ListNode* greaterTail = greater;
//
//		struct ListNode* less = (ListNode*)malloc(sizeof(ListNode));
//		less->next = NULL;
//		struct ListNode* lessTail = less;
//
//		while (pHead)
//		{
//			if (pHead->val < x)
//			{
//				lessTail->next = pHead;
//
//				lessTail = lessTail->next;
//			}
//
//			else
//			{
//				greaterTail->next = pHead;
//
//				greaterTail = greaterTail->next;
//			}
//			pHead = pHead->next;
//		}
//
//		greaterTail->next = NULL;
//		lessTail->next = greater->next;
//
//		struct ListNode* reHead = less->next;
//		free(greater);
//		free(less);
//		return reHead;
//	}
//};