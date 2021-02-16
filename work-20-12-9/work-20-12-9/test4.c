#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>

//��дһ�������ҵ������������ཻ����ʼ�ڵ㡣
//
//ʾ�� 1��
//���룺intersectVal = 8, listA = [4, 1, 8, 4, 5], listB = [5, 0, 1, 8, 4, 5], skipA = 2, skipB = 3
//�����Reference of the node with value = 8
//������ͣ��ཻ�ڵ��ֵΪ 8 ��ע�⣬������������ཻ����Ϊ 0�����Ӹ��Եı�ͷ��ʼ����
//���� A Ϊ[4, 1, 8, 4, 5]������ B Ϊ[5, 0, 1, 8, 4, 5]���� A �У��ཻ�ڵ�ǰ�� 2 ���ڵ㣻�� B �У��ཻ�ڵ�ǰ�� 3 ���ڵ㡣


/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
	struct ListNode *curA = headA;
	struct ListNode *curB = headB;

	while (curA)
	{
		while (curB)
		{
			if (curA == curB)
				return curA;

			curB = curB->next;
		}
		curB = headB;
		curA = curA->next;
	}

	return NULL;
}

int main()
{
	struct ListNode *headA = (struct ListNode *) malloc(sizeof(struct ListNode));
	headA->val = 4;

	struct ListNode *n1 = (struct ListNode *) malloc(sizeof(struct ListNode));
	n1->val = 1;

	struct ListNode *n2 = (struct ListNode *) malloc(sizeof(struct ListNode));
	n2->val = 8;

	struct ListNode *n3 = (struct ListNode *) malloc(sizeof(struct ListNode));
	n3->val = 4;

	struct ListNode *n4 = (struct ListNode *) malloc(sizeof(struct ListNode));
	n4->val = 5;

	headA->next = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;

	struct ListNode *headB = (struct ListNode *) malloc(sizeof(struct ListNode));
	headB->val = 5;

	struct ListNode *n11 = (struct ListNode *) malloc(sizeof(struct ListNode));
	n11->val = 0;

	struct ListNode *n22 = (struct ListNode *) malloc(sizeof(struct ListNode));
	n22->val = 1;
	struct ListNode *n33 = (struct ListNode *) malloc(sizeof(struct ListNode));
	n33->val = 8;
	struct ListNode *n44 = (struct ListNode *) malloc(sizeof(struct ListNode));
	n44->val = 4;
	struct ListNode *n55 = (struct ListNode *) malloc(sizeof(struct ListNode));
	n55->val = 5;

	headB->next = n11;
	n11->next = n22;
	n22->next = n33;
	n33->next = n44;
	n44->next = n55;
	n55->next = NULL;
	struct ListNode *P = getIntersectionNode(headA, headB);
	//struct ListNode *n = (struct ListNode *) malloc(sizeof(struct ListNode));
}
