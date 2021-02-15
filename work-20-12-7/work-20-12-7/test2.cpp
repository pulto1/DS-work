#define _CRT_SECURE_NO_WARNINGS

//����һ�����������һ��ʱ�临�Ӷ�ΪO(n), ����ռ临�Ӷ�ΪO(1)���㷨���ж����Ƿ�Ϊ���Ľṹ��
//
//����һ�������ͷָ��A���뷵��һ��boolֵ���������Ƿ�Ϊ���Ľṹ����֤������С�ڵ���900��
//
//����������
//1->2->2->1
//���أ�true


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
