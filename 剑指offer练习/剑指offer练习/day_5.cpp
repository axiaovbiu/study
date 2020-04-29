#define _CRT_SECURE_NO_WARNINGS 1

/*
面试题21. 调整数组顺序使奇数位于偶数前面
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。



示例：

输入：nums = [1,2,3,4]
输出：[1,3,2,4]
注：[3,1,2,4] 也是正确的答案之一。


提示：

1 <= nums.length <= 50000
1 <= nums[i] <= 10000
*/

//思路：定义双指针，start指向数组头，end指向数组尾，start找奇数，end找偶数，交换即可

class Solution {
public:
	vector<int> exchange(vector<int>& nums) {

		if (nums.empty())
			return nums;

		int start = 0;
		int end = nums.size() - 1;

		while (start < end)
		{
			while (start < end && (nums[start] & 0x1) == 1)
				start++;

			while (start < end && (nums[end] & 0x1) == 0)
				end--;

			std::swap(nums[start], nums[end]);
			start++;
			end--;
		}
		return nums;
	}
};