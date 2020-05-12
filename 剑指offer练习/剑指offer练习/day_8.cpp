#define _CRT_SECURE_NO_WARNINGS 1

/*
������29. ˳ʱ���ӡ����
����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֡�



ʾ�� 1��

���룺matrix = [[1,2,3],[4,5,6],[7,8,9]]
�����[1,2,3,6,9,8,7,4,5]
ʾ�� 2��

���룺matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
�����[1,2,3,4,8,12,11,10,9,5,6,7]
*/


//˼·����������߽磬���δ�ӡ
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {

		vector<int> res;
		if (matrix.empty())
			return res;

		//����߽�
		int left = 0, right = matrix[0].size() - 1, up = 0, down = matrix.size() - 1;

		while (1)
		{
			//��һ������Ҫ��ӡ,�����д�������
			for (int i = left; i <= right; ++i)
				res.push_back(matrix[up][i]);
			//���������߽�
			up++;
			if (up > down)
				break;

			//�������д�������
			for (int i = up; i <= down; ++i)
				res.push_back(matrix[i][right]);
			//���������߽�
			right--;
			if (right < left)
				break;

			//�����·�һ�д�������
			for (int i = right; i >= left; --i)
				res.push_back(matrix[down][i]);
			//���������߽�
			down--;
			if (down < up)
				break;

			//�������һ�д�������
			for (int i = down; i >= up; --i)
				res.push_back(matrix[i][left]);
			//���������߽�
			left++;
			if (left > right)
				break;
		}
		return res;
	}
};

/*
������30. ����min������ջ
����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ����СԪ�ص� min �����ڸ�ջ�У����� min��push �� pop ��ʱ�临�Ӷȶ��� O(1)��



ʾ��:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> ���� -3.
minStack.pop();
minStack.top();      --> ���� 0.
minStack.min();   --> ���� -2.
*/



//˼·�����ø���ջ�洢��Сֵ��������Ԫ���ǵ�ǰ��Сֵʱ������Ҳ���뵽����ջ�У�������Ԫ������Сֵʱ��ҲҪ������ջ�е�Ԫ�ص���

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		s.push(x);
		//�������ջΪ�ջ��߲���Ԫ�رȸ���ջ��Сʱ��Ҳ����Ԫ�ز��븨��ջ
		if (m.empty() || x <= m.top())
			m.push(x);
	}

	void pop() {
		//������Ԫ��Ϊ��Сֵ��ҲҪ������ջ�е�Ԫ�ص���
		if (s.top() == m.top())
			m.pop();
		s.pop();
	}

	int top() {
		return s.top();
	}

	int min() {
		return m.top();
	}
private
	stack<int> s;
	//����һ������ջ
	stack<int> m;
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(x);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->min();
*/



/*
������31. ջ��ѹ�롢��������
���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳�򡣼���ѹ��ջ���������־�����ȡ����磬���� {1,2,3,4,5} ��ĳջ��ѹջ���У����� {4,5,3,2,1} �Ǹ�ѹջ���ж�Ӧ��һ���������У��� {4,3,5,1,2} �Ͳ������Ǹ�ѹջ���еĵ������С�



ʾ�� 1��

���룺pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
�����true
���ͣ����ǿ��԰�����˳��ִ�У�
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
ʾ�� 2��

���룺pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
�����false
���ͣ�1 ������ 2 ֮ǰ������
*/


//˼·�����ø���ջ��ģ�������̣���ʾ��2λ������ջ�в��� 1 2 3 4��ջ��Ԫ�����ջ���е�һ��Ԫ����ͬ������3���ٵ���4������5������5��ջ��Ϊ2����������Ϊ1���߲�����
class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		if (pushed.size() != popped.size())
			return false;

		stack<int> s;
		int n = popped.size();
		int j = 0;
		for (int i = 0; i < n; ++i)
		{
			s.push(pushed[i]);
			while (!s.empty() && s.top() == popped[j])
			{
				s.pop();
				j++;
			}
		}
		if (s.empty())
			return true;
		else
			return false;
	}
};

/*
������32 - I. ���ϵ��´�ӡ������
���ϵ��´�ӡ����������ÿ���ڵ㣬ͬһ��Ľڵ㰴�մ����ҵ�˳���ӡ��



����:
����������: [3,9,20,null,null,15,7],

3
/ \
9  20
/  \
15   7
���أ�

[3,9,20,15,7]
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


//˼·�����ö��������ȳ������ʣ����α����������Һ���
class Solution {
public:
	vector<int> levelOrder(TreeNode* root) {

		vector<int> res;
		if (root == nullptr)
			return res;
		queue<TreeNode*> q;
		q.push(root);
		TreeNode *cur;

		while (!q.empty())
		{
			cur = q.front();
			q.pop();
			if (cur->left)
				q.push(cur->left);
			if (cur->right)
				q.push(cur->right);
			res.push_back(cur->val);
		}
		return res;
	}
};