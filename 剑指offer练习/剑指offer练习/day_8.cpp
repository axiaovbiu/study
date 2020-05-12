#define _CRT_SECURE_NO_WARNINGS 1

/*
面试题29. 顺时针打印矩阵
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。



示例 1：

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：

输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
*/


//思路：收缩矩阵边界，依次打印
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {

		vector<int> res;
		if (matrix.empty())
			return res;

		//定义边界
		int left = 0, right = matrix[0].size() - 1, up = 0, down = matrix.size() - 1;

		while (1)
		{
			//第一行总是要打印,将顶行存入数组
			for (int i = left; i <= right; ++i)
				res.push_back(matrix[up][i]);
			//向下收缩边界
			up++;
			if (up > down)
				break;

			//将最右列存入数组
			for (int i = up; i <= down; ++i)
				res.push_back(matrix[i][right]);
			//向左收缩边界
			right--;
			if (right < left)
				break;

			//将最下方一行存入数组
			for (int i = right; i >= left; --i)
				res.push_back(matrix[down][i]);
			//向上收缩边界
			down--;
			if (down < up)
				break;

			//将最左侧一列存入数组
			for (int i = down; i >= up; --i)
				res.push_back(matrix[i][left]);
			//向右收缩边界
			left++;
			if (left > right)
				break;
		}
		return res;
	}
};

/*
面试题30. 包含min函数的栈
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。



示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.min();   --> 返回 -2.
*/



//思路：利用辅助栈存储最小值，当插入元素是当前最小值时，将其也插入到辅助栈中，当弹出元素是最小值时，也要将辅助栈中的元素弹出

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		s.push(x);
		//如果辅助栈为空或者插入元素比辅助栈顶小时，也将该元素插入辅助栈
		if (m.empty() || x <= m.top())
			m.push(x);
	}

	void pop() {
		//若弹出元素为最小值，也要将辅助栈中的元素弹出
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
	//定义一个辅助栈
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
面试题31. 栈的压入、弹出序列
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。



示例 1：

输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
输出：true
解释：我们可以按以下顺序执行：
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
示例 2：

输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
输出：false
解释：1 不能在 2 之前弹出。
*/


//思路：利用辅助栈，模拟插入过程，以示列2位例，往栈中插入 1 2 3 4，栈顶元素与出栈序列第一个元素相同，弹出3，再弹出4，插入5，弹出5，栈顶为2，弹出序列为1两者不符合
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
面试题32 - I. 从上到下打印二叉树
从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。



例如:
给定二叉树: [3,9,20,null,null,15,7],

3
/ \
9  20
/  \
15   7
返回：

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


//思路：利用队列先入先出的性质，依次保存树的左右孩子
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