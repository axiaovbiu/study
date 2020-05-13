#define _CRT_SECURE_NO_WARNINGS 1

/*
面试题33. 二叉搜索树的后序遍历序列
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。



参考以下这颗二叉搜索树：

5
/ \
2   6
/ \
1   3
示例 1：

输入: [1,6,3,2,5]
输出: false
示例 2：

输入: [1,3,2,6,5]
输出: true
*/


//思路：后序遍历的结果中，最后一个节点即为根节点。
//		二叉搜索树的左孩子小于根节点，右孩子大于根节点，遍历数组，找到第一个大于根节点的位置j
//		通过j将数组划分为左右孩子，分别判断左右孩子是否合法
class Solution {
public:
	bool verifyPostorder(vector<int>& postorder) {
		if (postorder.size() == 0)
			return true;
		return helper(postorder, 0, postorder.size() - 1);
	}

	bool helper(vector<int> &postorder, int start, int end)
	{
		//只有一个节点的树，必为二叉搜索树
		if (start >= end)
			return true;
		//数组最后一个元素即为根节点
		int root = postorder[end];

		//寻找左右子树的分界点
		int i = start;
		for (; i < end; ++i)
		{
			if (postorder[i] > root)
				break;
		}

		//若右子树中的值小于根节点，则不为二叉搜索树
		int j = i;
		for (; j <= end; ++j)
		{
			if (postorder[j] < root)
				return false;
		}

		return helper(postorder, start, i - 1) && helper(postorder, i, end - 1);
	}
};



/*
面试题35. 复杂链表的复制
请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。
*/



/*
// Definition for a Node.
class Node {
public:
int val;
Node* next;
Node* random;

Node(int _val) {
val = _val;
next = NULL;
random = NULL;
}
};
*/

//思路一利用哈希表，为原结点和拷贝结点建立映射关系，通过映射关系拷贝链表
class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (head == nullptr)
			return head;

		map<Node*, Node*> m;

		//使用原结点与复制结点构成映射
		Node *cur = head;
		while (cur)
		{
			Node *tmp = new Node(cur->val);
			m.insert(make_pair(cur, tmp));
			cur = cur->next;
		}

		cur = head;

		//构建新的链表
		while (cur)
		{
			if (cur->next)
				m[cur]->next = m[cur->next];
			if (cur->random)
				m[cur]->random = m[cur->random];
			cur = cur->next;
		}
		return m[head];

	}
};