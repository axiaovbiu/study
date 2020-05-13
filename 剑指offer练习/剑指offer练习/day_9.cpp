#define _CRT_SECURE_NO_WARNINGS 1

/*
������33. �����������ĺ����������
����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�����������������򷵻� true�����򷵻� false���������������������������ֶ�������ͬ��



�ο�������Ŷ�����������

5
/ \
2   6
/ \
1   3
ʾ�� 1��

����: [1,6,3,2,5]
���: false
ʾ�� 2��

����: [1,3,2,6,5]
���: true
*/


//˼·����������Ľ���У����һ���ڵ㼴Ϊ���ڵ㡣
//		����������������С�ڸ��ڵ㣬�Һ��Ӵ��ڸ��ڵ㣬�������飬�ҵ���һ�����ڸ��ڵ��λ��j
//		ͨ��j�����黮��Ϊ���Һ��ӣ��ֱ��ж����Һ����Ƿ�Ϸ�
class Solution {
public:
	bool verifyPostorder(vector<int>& postorder) {
		if (postorder.size() == 0)
			return true;
		return helper(postorder, 0, postorder.size() - 1);
	}

	bool helper(vector<int> &postorder, int start, int end)
	{
		//ֻ��һ���ڵ��������Ϊ����������
		if (start >= end)
			return true;
		//�������һ��Ԫ�ؼ�Ϊ���ڵ�
		int root = postorder[end];

		//Ѱ�����������ķֽ��
		int i = start;
		for (; i < end; ++i)
		{
			if (postorder[i] > root)
				break;
		}

		//���������е�ֵС�ڸ��ڵ㣬��Ϊ����������
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
������35. ��������ĸ���
��ʵ�� copyRandomList ����������һ�����������ڸ��������У�ÿ���ڵ������һ�� next ָ��ָ����һ���ڵ㣬����һ�� random ָ��ָ�������е�����ڵ���� null��
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

//˼·һ���ù�ϣ��Ϊԭ���Ϳ�����㽨��ӳ���ϵ��ͨ��ӳ���ϵ��������
class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (head == nullptr)
			return head;

		map<Node*, Node*> m;

		//ʹ��ԭ����븴�ƽ�㹹��ӳ��
		Node *cur = head;
		while (cur)
		{
			Node *tmp = new Node(cur->val);
			m.insert(make_pair(cur, tmp));
			cur = cur->next;
		}

		cur = head;

		//�����µ�����
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