////����һ�����ͷָ�� ListNode* pHead����һ��ֵx��
////��дһ�δ��뽫����С��x�Ľ������������֮ǰ���Ҳ��ܸı�ԭ��������˳�򣬷����������к�������ͷָ�롣
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