#define _CRT_SECURE_NO_WARNINGS 1




/*
������22. �����е�����k���ڵ�
����һ����������������е�����k���ڵ㡣Ϊ�˷��ϴ�����˵�ϰ�ߣ������1��ʼ�������������β�ڵ��ǵ�����1���ڵ㡣
���磬һ��������6���ڵ㣬��ͷ�ڵ㿪ʼ�����ǵ�ֵ������1��2��3��4��5��6���������ĵ�����3���ڵ���ֵΪ4�Ľڵ㡣



ʾ����

����һ������: 1->2->3->4->5, �� k = 2.

�������� 4->5.
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/


//˼·��˫ָ�룬��ָ������k-1������·���飬����ָ���ߵ���β����ָ��ָ��ľ��ǵ�����k�����

class Solution {
public:
	ListNode* getKthFromEnd(ListNode* head, int k) {
		//�ж�ͷ����Ƿ���Ч
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