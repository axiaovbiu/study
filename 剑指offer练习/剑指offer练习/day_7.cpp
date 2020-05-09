#define _CRT_SECURE_NO_WARNINGS 1


/*
������24. ��ת����
����һ������������һ�������ͷ�ڵ㣬��ת�����������ת�������ͷ�ڵ㡣



ʾ��:

����: 1->2->3->4->5->NULL
���: 5->4->3->2->1->NULL
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/



//˼·���ı䵱ǰ�ڵ��ָ����ǰ���浱ǰ�ڵ����һ����㣬��ֹ����Ͽ�
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr)
			return head;

		ListNode *phead = head;
		ListNode *pcur = head;
		ListNode *pre = nullptr;

		while (pcur)
		{
			ListNode *pnext = pcur->next;
			if (pnext == nullptr)
				phead = pcur;
			pcur->next = pre;
			pre = pcur;
			pcur = pnext;
		}
		return phead;
	}
};


/*
������25. �ϲ��������������
����������������������ϲ�����������ʹ�������еĽڵ���Ȼ�ǵ�������ġ�

ʾ��1��

���룺1->2->4, 1->3->4
�����1->1->2->3->4->4
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/


//�ݹ飺
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr)
			return l2;
		if (l2 == nullptr)
			return l1;

		ListNode *node = nullptr;
		if (l1->val < l2->val)
		{
			node = l1;
			l1->next = mergeTwoLists(l1->next, l2);
		}
		else
		{
			node = l2;
			l2->next = mergeTwoLists(l1, l2->next);
		}
		return node;
	}
};


//������
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		
		//�ж������Ƿ�Ϊ�գ�����һ��Ϊ�գ���ϲ�������������һ������
		if (l1 == nullptr)
			return l2;
		if (l2 == nullptr)
			return l1;

		//��������ͷ��㣬�Ա���Һϲ����ͷ���
		ListNode *curHead = new ListNode(-1);
		ListNode *cur = curHead;
		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				cur->next = l1;
				l1 = l1->next;
			}
			else
			{
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}

		//��ĳ�������Ѿ�Ϊ�գ���һ������Ϊ�գ������ֱ�ӽ���һ������ʣ��Ľ������
		if (l1 == nullptr)
			cur->next = l2;
		if (l2 == nullptr)
			cur->next = l1;

		return curHead->next;
	}
};



/*
������26. �����ӽṹ
�������ö�����A��B���ж�B�ǲ���A���ӽṹ��(Լ��������������һ�������ӽṹ)

B��A���ӽṹ�� �� A���г��ֺ�B��ͬ�Ľṹ�ͽڵ�ֵ��

����:
�������� A:

3
/ \
4   5
/ \
1   2
�������� B��

4
/
1
���� true����Ϊ B �� A ��һ������ӵ����ͬ�Ľṹ�ͽڵ�ֵ��

ʾ�� 1��

���룺A = [1,2,3], B = [3,1]
�����false
ʾ�� 2��

���룺A = [3,4,5,1,2], B = [4,1]
�����true
*/


/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/


//˼·������ԭ����Ѱ�����������ڵ���ͬ���������ж����������ҽ���Ƿ���ԭ����ͬ
class Solution {
public:
	bool isSubStructure(TreeNode* A, TreeNode* B) {
		bool result = false;
		if (A && B)
		{
			if (A->val == B->val)
				result = hasSubStructure(A, B);
			if (!result)
				result = isSubStructure(A->left, B);
			if (!result)
				result = isSubStructure(A->right, B);
		}
		return result;
	}
	bool hasSubStructure(TreeNode *A, TreeNode *B)
	{
		//�����Ѿ��ж���ϣ�����ͬ
		if (B == nullptr)
			return true;
		//ԭ����������ͬ����ԭ��С������
		if (A == nullptr)
			return false;
		//ԭ����������ͬ
		if (A->val != B->val)
			return false;

		return hasSubStructure(A->left, B->left) && hasSubStructure(A->right, B->right);
	}
};


/*
������27. �������ľ���
�����һ������������һ�����������ú���������ľ���

�������룺

4
/   \
2     7
/ \   / \
1   3 6   9
���������

4
/   \
7     2
/ \   / \
9   6 3   1



ʾ�� 1��

���룺root = [4,2,7,1,3,6,9]
�����[4,7,2,9,6,3,1]
*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

//˼·���ݹ��жϣ����ϵ��½������ڵ�����Һ���
class Solution {
public:
	TreeNode* mirrorTree(TreeNode* root) {
		if (root == nullptr)
			return root;

		//�������Һ���
		TreeNode *tempNode = root->left;
		root->left = root->right;
		root->right = tempNode;

		//���¼����������������Һ���
		if (root->left)
			mirrorTree(root->left);
		if (root->right)
			mirrorTree(root->right);

		return root;
	}
};


/*
������28. �ԳƵĶ�����
��ʵ��һ�������������ж�һ�ö������ǲ��ǶԳƵġ����һ�ö����������ľ���һ������ô���ǶԳƵġ�

���磬������ [1,2,2,3,4,4,3] �ǶԳƵġ�

1
/ \
2   2
/ \ / \
3  4 4  3
����������� [1,2,2,null,3,null,3] ���Ǿ���ԳƵ�:

1
/ \
2   2
\   \
3    3



ʾ�� 1��

���룺root = [1,2,2,3,4,4,3]
�����true
ʾ�� 2��

���룺root = [1,2,2,null,3,null,3]
�����false
*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

//˼·���жϾ���ֻ��Ҫ�Ƚϵ�һ��������ڵ���ڶ��������ҽ�㣬��һ�������ҽ����ڶ���������ڵ��Ƿ���ͬ
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		//����Ҳ�ǶԳƵ�
		return help(root, root);
	}

	bool help(TreeNode *root1, TreeNode *root2)
	{
		//�������������꣬����true
		if (root1 == nullptr && root2 == nullptr)
			return true;
		//��һ����Ϊ�գ�һ�ò�Ϊ�����ǶԳ�
		if (root1 == nullptr || root2 == nullptr)
			return false;
		//��������㲻ͬҲ���ǶԳ�
		if (root1->val != root2->val)
			return false;

		return help(root1->left, root2->right) && help(root1->right, root2->left);

	}
};