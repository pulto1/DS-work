#define _CRT_SECURE_NO_WARNINGS

//��תһ��������
//
//ʾ�� :
//���� : 1->2->3->4->5->NULL
//��� : 5->4->3->2->1->NULL
//
// ���� :
//����Ե�����ݹ�ط�ת�������ܷ������ַ����������⣿

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