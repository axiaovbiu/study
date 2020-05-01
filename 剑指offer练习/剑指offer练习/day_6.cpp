#define _CRT_SECURE_NO_WARNINGS 1




/*
面试题22. 链表中倒数第k个节点
输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。
例如，一个链表有6个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。



示例：

给定一个链表: 1->2->3->4->5, 和 k = 2.

返回链表 4->5.
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/


//思路：双指针，快指针先走k-1步，边路数组，当快指针走到结尾，慢指针指向的就是倒数第k个结点

class Solution {
public:
	ListNode* getKthFromEnd(ListNode* head, int k) {
		//判断头结点是否有效
		if (head == nullptr)
			return nullptr;

		if (k == 0)
			return head;
		ListNode *pfast = head;
		ListNode *pslow = head;

		for (int i = 0; i < k - 1; i++)
		{
			if (pfast->next != nullptr)
				pfast = pfast->next;
			else
				return nullptr;
		}

		while (pfast->next != nullptr)
		{
			pfast = pfast->next;
			pslow = pslow->next;
		}
		return pslow;

	}
};