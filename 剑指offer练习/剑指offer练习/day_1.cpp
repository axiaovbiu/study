#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
/*
������03. �������ظ�������
�ҳ��������ظ������֡�


��һ������Ϊ n ������ nums ����������ֶ��� 0��n-1 �ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�
Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡�

ʾ�� 1��

���룺
[2, 3, 1, 0, 2, 5, 3]
�����2 �� 3


���ƣ�

2 <= n <= 100000
*/


//����һ��ʹ�ù�ϣ�����Ԫ�أ��ж��Ƿ��ظ�
class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		unordered_map<int, int> m;
		for (int i = 0; i < nums.size(); i++)
		{
			if (m[nums[i]] == 1)
				return nums[i];
			else
				m[nums[i]]++;
		}
		return -1;
	}
};


//�����������������ж�ǰһ������һ���Ƿ����
class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size() - 1; i++)
		{
			if (nums[i] == nums[i + 1])
				return nums[i];
		}
		return -1;
	}
};