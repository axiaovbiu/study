#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
/*
面试题03. 数组中重复的数字
找出数组中重复的数字。


在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

示例 1：

输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3


限制：

2 <= n <= 100000
*/


//方法一：使用哈希表插入元素，判断是否重复
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


//方法二：数组排序，判断前一个与下一个是否相等
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