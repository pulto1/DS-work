#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

struct ListNode* removeElements(struct ListNode* head, int val)
{
	struct ListNode* cur = head;
	if (head == NULL)
	{
		return NULL;
	}

	else
	{
		struct ListNode* prev = NULL;
		while (cur->val == val)
		{
			head = head->next;
			cur = head;
			if (head == NULL)
				return NULL;
		}
		while (cur != NULL)
		{
			if (cur->val == val)
			{
				prev->next = cur->next;
				cur = cur->next;
				if (prev->next == NULL)
				{
					break;
				}
			}
			else
			{
				prev = cur;
				cur = cur->next;
			}
		}
	}
	return head;
}