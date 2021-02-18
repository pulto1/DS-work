#define _CRT_SECURE_NO_WARNINGS

//给你一个长度为 n 的链表，每个节点包含一个额外增加的随机指针 random ，该指针可以指向链表中的任何节点或空节点。
//
//构造这个链表的 深拷贝。 深拷贝应该正好由 n 个 全新 节点组成，其中每个新节点的值都设为其对应的原节点的值。
//新节点的 next 指针和 random 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。
//复制链表中的指针都不应指向原链表中的节点 。
//
//例如，如果原链表中有 X 和 Y 两个节点，其中 X.random--> Y 。那么在复制链表中对应的两个节点 x 和 y ，同样有 x.random--> y 。
//返回复制链表的头节点。
//用一个由 n 个节点组成的链表来表示输入 / 输出中的链表。每个节点用一个 [val, random_index] 表示：
//val：一个表示 Node.val 的整数。
//random_index：随机指针指向的节点索引（范围从 0 到 n - 1）；如果不指向任何节点，则为  null 。
//你的代码 只 接受原链表的头节点 head 作为传入参数。

/**
* Definition for a Node.
* struct Node {
*     int val;
*     struct Node *next;
*     struct Node *random;
* };
*/

struct Node* copyRandomList(struct Node* head)
{
	//哨兵结点
	struct Node* newHead = (struct Node*) malloc(sizeof(struct Node));
	struct Node* curNewList = newHead;
	struct Node* curList = head;

	//创建新链表，拷贝原链表的val和next指向关系
	while (curList)
	{
		struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
		newNode->val = curList->val;
		curNewList->next = newNode;
		curNewList = curNewList->next;
		curList = curList->next;
	}

	curNewList->next = NULL;
	struct Node* del = newHead;
	newHead = newHead->next;
	free(del);

	//拷贝random指向关系
	curList = head;
	curNewList = newHead;
	while (curList)
	{
		struct Node* random = curList->random;
		if (random == NULL)
		{
			curNewList->random = NULL;
			curNewList = curNewList->next;
		}

		//原链表的random指向第几个结点，新链表的random就指向第几个结点
		else
		{
			int gap = 0;
			struct Node* retHead = head;
			while (retHead != random)
			{
				gap++;
				retHead = retHead->next;
			}

			struct Node* retNew = newHead;
			while (gap--)
			{
				retNew = retNew->next;
			}

			curNewList->random = retNew;
			curNewList = curNewList->next;
		}
		curList = curList->next;
	}

	return newHead;
}