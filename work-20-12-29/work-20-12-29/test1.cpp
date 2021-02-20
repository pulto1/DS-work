#define _CRT_SECURE_NO_WARNINGS

//��Ŀ����
//��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣 
//���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5
//
//ʾ��1
//����
//{ 1, 2, 3, 3, 4, 4, 5 }
//����ֵ
//����
//{ 1, 2, 5 }

/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
*/
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL)
			return NULL;

		ListNode* prev = NULL;
		ListNode* cur = pHead;
		ListNode* next = pHead->next;

		while (next)
		{
			if (cur->val != next->val)
			{
				prev = cur;
				cur = next;
				next = next->next;
			}

			else
			{
				while (next && cur->val == next->val)
				{
					next = next->next;
				}

				while (cur != next)
				{
					ListNode* del = cur;

					cur = cur->next;

					if (prev == NULL)
						pHead = cur;
					else
						prev->next = cur;
					free(del);
				}
				if (next)
					next = next->next;
			}
		}

		return pHead;
	}
};