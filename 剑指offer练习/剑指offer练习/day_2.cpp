#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;



/*
面试题04. 二维数组中的查找
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

 

示例:

现有矩阵 matrix 如下：

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。

给定 target = 20，返回 false。
*/


//思路：因为二维矩阵从左到右，从下到上依次递增，取矩阵右上角的值与target比较，
//若大于target则剔除一列，若小于target则剔除一行，若等于则返回结果

class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		if (matrix.empty())
			return false;

		int n = matrix.size() - 1;
		int m = matrix[0].size() - 1;

		int row = 0;
		int col = m;

		while (row <= n && col >= 0)
		{
			if (matrix[row][col] > target)
				col--;
			else if (matrix[row][col] < target)
				row++;
			else
				return true;
		}
		return false;

	}
};




/*
面试题05. 替换空格
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。



示例 1：

输入：s = "We are happy."
输出："We%20are%20happy."
*/



//思路：从前向后遍历字符串，遇到空格就替换，需要搬移元素，时间复杂度是O(N2)
//		遍历字符串，记录空格个数，扩大空间容量，定义两个指针，一个指
//		向扩容后的结尾，一个指向原始结尾，从后向前遍历字符串，遇到空格就替换，
//		时间复杂度是O(N)
class Solution {
public:
	string replaceSpace(string s) {
		if (s.empty())
			return s;

		int len = s.size();
		int bankCount = 0;
		for (int i = 0; i < len; i++)
		{
			if (s[i] == ' ')
				bankCount++;
		}
		s.resize(len + bankCount * 2);
		int newLen = s.size();

		int end = len - 1;
		int newEnd = newLen - 1;
		while (end >= 0)
		{
			if (s[end] == ' ')
			{
				s[newEnd--] = '0';
				s[newEnd--] = '2';
				s[newEnd--] = '%';
			}
			else
			{
				s[newEnd--] = s[end];
			}
			end--;
		}
		return s;
	}
};



/*
面试题06. 从尾到头打印链表
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。



示例 1：

输入：head = [1,3,2]
输出：[2,3,1]
*/




/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

//方法一：按顺序将结点值存入vector，逆置数组

class Solution {
public:
	vector<int> reversePrint(ListNode* head) {

		vector<int> res;
		if (head == nullptr)
			return res;

		ListNode *phead = head;
		while (phead)
		{
			res.push_back(phead->val);
			phead = phead->next;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};


//方法二：从尾到头打印链表，就是先入后出的过程，用栈储存结点值，打印栈顶，直到栈为空

class Solution {
public:
	vector<int> reversePrint(ListNode* head) {

		vector<int> res;
		if (head == nullptr)
			return res;

		stack<int> s;
		ListNode *phead = head;
		while (phead)
		{
			s.push(phead->val);
			phead = phead->next;
		}

		while (!s.empty())
		{
			res.push_back(s.top());
			s.pop();
		}
		return res;
	}
};