#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;



/*
������04. ��ά�����еĲ���
��һ�� n * m �Ķ�ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������

 

ʾ��:

���о��� matrix ���£�

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
���� target = 5������ true��

���� target = 20������ false��
*/


//˼·����Ϊ��ά��������ң����µ������ε�����ȡ�������Ͻǵ�ֵ��target�Ƚϣ�
//������target���޳�һ�У���С��target���޳�һ�У��������򷵻ؽ��

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
������05. �滻�ո�
��ʵ��һ�����������ַ��� s �е�ÿ���ո��滻��"%20"��



ʾ�� 1��

���룺s = "We are happy."
�����"We%20are%20happy."
*/



//˼·����ǰ�������ַ����������ո���滻����Ҫ����Ԫ�أ�ʱ�临�Ӷ���O(N2)
//		�����ַ�������¼�ո����������ռ���������������ָ�룬һ��ָ
//		�����ݺ�Ľ�β��һ��ָ��ԭʼ��β���Ӻ���ǰ�����ַ����������ո���滻��
//		ʱ�临�Ӷ���O(N)
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
������06. ��β��ͷ��ӡ����
����һ�������ͷ�ڵ㣬��β��ͷ����������ÿ���ڵ��ֵ�������鷵�أ���



ʾ�� 1��

���룺head = [1,3,2]
�����[2,3,1]
*/




/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

//����һ����˳�򽫽��ֵ����vector����������

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


//����������β��ͷ��ӡ���������������Ĺ��̣���ջ������ֵ����ӡջ����ֱ��ջΪ��

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