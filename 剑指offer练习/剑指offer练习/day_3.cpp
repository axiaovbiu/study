#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

/*
������07. �ؽ�������
����ĳ��������ǰ���������������Ľ�������ؽ��ö����������������ǰ���������������Ľ���ж������ظ������֡�



���磬����

ǰ����� preorder = [3,9,20,15,7]
������� inorder = [9,3,15,20,7]
�������µĶ�������

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


//˼·������"����"˼�롣
//ǰ������ĵ�һ��Ԫ�ؾ��Ǹ��ڵ㣬�������������ҵ�����ڵ㣬�ڵ����Ϊ���ӣ��Ҳ�Ϊ
//�Һ��ӣ������Ϊ�����֡��ݹ飬��������Ρ�

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
������09. ������ջʵ�ֶ���
������ջʵ��һ�����С����е��������£���ʵ�������������� appendTail �� deleteHead ���ֱ�����ڶ���β�������������ڶ���ͷ��ɾ�������Ĺ��ܡ�(��������û��Ԫ�أ�deleteHead �������� -1 )



ʾ�� 1��

���룺
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
�����[null,null,3,-1]
ʾ�� 2��

���룺
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
�����[null,-1,null,null,5,2]
*/



//˼·��ջ�Ǻ����ȳ��������������ȳ���ʹ������ջ��ʵ�ֶ��С�
//����ʱ��ֱ�ӽ�Ԫ�ز����һ��ջs1��ͷɾʱ���жϵڶ���ջs2�Ƿ�Ϊ��
//��Ϊ���գ�ֱ��s2.pop(),��Ϊ�գ���s1�е�Ԫ��ѹ��s2���ٽ���pop
class CQueue {
public:
	CQueue() {

	}

	void appendTail(int value) {
		//��Ԫ��ֱ�Ӳ���s1
		s1.push(value);
	}

	int deleteHead() {
		if (s1.empty() && s2.empty())
			return -1;
		//��s2Ϊ��,��s1��Ԫ�ز���s2
		if (s2.empty())
		{
			while (!s1.empty())
			{
				s2.push(s1.top());
				s1.pop();
			}
		}
		//s2ջ��Ԫ�ؾ������Ƚ�����е�Ԫ��
		int tmp = s2.top();
		s2.pop();
		return tmp;
	}
private:
	stack<int> s1;
	stack<int> s2;
};


/*
������10- I. 쳲���������
дһ������������ n ����쳲�������Fibonacci�����еĵ� n �쳲��������еĶ������£�

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), ���� N > 1.
쳲����������� 0 �� 1 ��ʼ��֮���쳲�������������֮ǰ��������Ӷ��ó���

����Ҫȡģ 1e9+7��1000000007����������ʼ���Ϊ��1000000008���뷵�� 1��



ʾ�� 1��

���룺n = 2
�����1
ʾ�� 2��

���룺n = 5
�����5
*/


//˼·һ��ʹ�õݹ�
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

//˼·����ʹ�ö�̬�滮˼��

//״̬���壺F(i)  ��i��쳲�������
//״̬ת�����̣�F(i) = F(i - 1) + F(i - 2)
//��ʼֵ��F(0) = 0, F(1) = 1
//����ֵ��F(i)
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