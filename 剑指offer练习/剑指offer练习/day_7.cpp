#define _CRT_SECURE_NO_WARNINGS 1


/*
面试题24. 反转链表
定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。



示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/



//思路：改变当前节点的指向，提前保存当前节点的下一个结点，防止链表断开
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
面试题25. 合并两个排序的链表
输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

示例1：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/


//递归：
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


//迭代：
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
		
		//判断链表是否为空，若有一个为空，则合并后的链表就是另一个链表
		if (l1 == nullptr)
			return l2;
		if (l2 == nullptr)
			return l1;

		//创建辅助头结点，以便查找合并后的头结点
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

		//当某个链表已经为空，另一个链表不为空，则可以直接将另一个链表剩余的结点连接
		if (l1 == nullptr)
			cur->next = l2;
		if (l2 == nullptr)
			cur->next = l1;

		return curHead->next;
	}
};



/*
面试题26. 树的子结构
输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

B是A的子结构， 即 A中有出现和B相同的结构和节点值。

例如:
给定的树 A:

3
/ \
4   5
/ \
1   2
给定的树 B：

4
/
1
返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。

示例 1：

输入：A = [1,2,3], B = [3,1]
输出：false
示例 2：

输入：A = [3,4,5,1,2], B = [4,1]
输出：true
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


//思路：先在原树中寻找与子树根节点相同的树，再判断子树的左右结点是否与原树相同
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
		//子树已经判断完毕，都相同
		if (B == nullptr)
			return true;
		//原树和子树相同，但原树小于子树
		if (A == nullptr)
			return false;
		//原树和子树不同
		if (A->val != B->val)
			return false;

		return hasSubStructure(A->left, B->left) && hasSubStructure(A->right, B->right);
	}
};


/*
面试题27. 二叉树的镜像
请完成一个函数，输入一个二叉树，该函数输出它的镜像。

例如输入：

4
/   \
2     7
/ \   / \
1   3 6   9
镜像输出：

4
/   \
7     2
/ \   / \
9   6 3   1



示例 1：

输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]
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

//思路：递归判断，自上到下交换根节点的左右孩子
class Solution {
public:
	TreeNode* mirrorTree(TreeNode* root) {
		if (root == nullptr)
			return root;

		//交换左右孩子
		TreeNode *tempNode = root->left;
		root->left = root->right;
		root->right = tempNode;

		//向下继续遍历，交换左右孩子
		if (root->left)
			mirrorTree(root->left);
		if (root->right)
			mirrorTree(root->right);

		return root;
	}
};


/*
面试题28. 对称的二叉树
请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

1
/ \
2   2
/ \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

1
/ \
2   2
\   \
3    3



示例 1：

输入：root = [1,2,2,3,4,4,3]
输出：true
示例 2：

输入：root = [1,2,2,null,3,null,3]
输出：false
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

//思路；判断镜像，只需要比较第一棵树的左节点与第二棵树的右结点，第一棵树的右结点与第二棵树的左节点是否相同
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		//空树也是对称的
		return help(root, root);
	}

	bool help(TreeNode *root1, TreeNode *root2)
	{
		//两棵树都遍历完，返回true
		if (root1 == nullptr && root2 == nullptr)
			return true;
		//有一棵树为空，一棵不为空则不是对称
		if (root1 == nullptr || root2 == nullptr)
			return false;
		//两棵树结点不同也不是对称
		if (root1->val != root2->val)
			return false;

		return help(root1->left, root2->right) && help(root1->right, root2->left);

	}
};