#define _CRT_SECURE_NO_WARNINGS

//对于一个链表，请设计一个时间复杂度为O(n), 额外空间复杂度为O(1)的算法，判断其是否为回文结构。
//
//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。
//
//测试样例：
//1->2->2->1
//返回：true


//struct ListNode {
//int val;
//struct ListNode *next;
//ListNode(int x) : val(x), next(NULL) {}
//};

class PalindromeList {
public:
	bool chkPalindrome(ListNode* A)
	{
		bool flag = true;
		if (A == NULL)
			return flag;

		ListNode* n1 = NULL;
		ListNode* n2 = A;
		ListNode* n3 = A->next;
		while (n2)
		{
			n2->next = n1;

			n1 = n2;
			n2 = n3;
			if (n3 != NULL)
				n3 = n3->next;
		}

		ListNode* head = A;
		while (head != NULL)
		{
			if (head->val != n1->val)
			{
				flag = false;
				break;
			}

			head = head->next;
			n1 = n1->next;
		}

		return flag;
	}
};
