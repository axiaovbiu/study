#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

/*
面试题07. 重建二叉树
输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。



例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

3
/ \
9  20
/  \
15   7
*/



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//思路：利用"分治"思想。
//前序数组的第一个元素就是根节点，在中序数组中找到这个节点，节点左侧为左孩子，右侧为
//右孩子，数组分为两部分。递归，将数组分治。

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty() || inorder.empty())
			return nullptr;

		TreeNode *root = new TreeNode(preorder[0]);

		auto pos = find(inorder.begin(), inorder.end(), preorder[0]);

		int len = pos - inorder.begin();

		vector<int> leftPre(preorder.begin() + 1, preorder.begin() + 1 + len);
		vector<int> leftIn(inorder.begin(), inorder.begin() + len);
		vector<int> rightPre(preorder.begin() + 1 + len, preorder.end());
		vector<int> rightIn(inorder.begin() + len + 1, inorder.end());

		root->left = buildTree(leftPre, leftIn);
		root->right = buildTree(rightPre, rightIn);
		return root;
		
	}
};



/*
面试题09. 用两个栈实现队列
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )



示例 1：

输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
示例 2：

输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
*/



//思路：栈是后入先出，队列是先入先出，使用两个栈来实现队列。
//插入时，直接将元素插入第一个栈s1，头删时，判断第二个栈s2是否为空
//若为不空，直接s2.pop(),若为空，则将s1中的元素压入s2，再进行pop
class CQueue {
public:
	CQueue() {

	}

	void appendTail(int value) {
		//将元素直接插入s1
		s1.push(value);
	}

	int deleteHead() {
		if (s1.empty() && s2.empty())
			return -1;
		//若s2为空,将s1中元素插入s2
		if (s2.empty())
		{
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
		//s2栈顶元素就是最先进入队列的元素
		int tmp = s2.top();
		s2.pop();
		return tmp;
	}
private:
	stack<int> s1;
	stack<int> s2;
};


/*
面试题10- I. 斐波那契数列
写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项。斐波那契数列的定义如下：

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。



示例 1：

输入：n = 2
输出：1
示例 2：

输入：n = 5
输出：5
*/


//思路一：使用递归
class Solution {
public:
	int fib(int n) {
		if (n == 0)
			return 0;
		if (n == 1)
			return 1;
		return fib(n - 1) + fib(n - 2);
	}
};

//思路二：使用动态规划思想

//状态定义：F(i)  第i个斐波那契数
//状态转换方程：F(i) = F(i - 1) + F(i - 2)
//初始值：F(0) = 0, F(1) = 1
//返回值：F(i)
class Solution {
public:
	int fib(int n) {
		if (n == 0)
			return 0;
		if (n == 1)
			return 1;

		int fib1 = 1, fib2 = 0;
		int ret;
		for (int i = 2; i <= n; i++)
		{
			ret = fib1 + fib2;
			fib2 = fib1;
			fib1 = ret;
		}
		return ret;
	}
};