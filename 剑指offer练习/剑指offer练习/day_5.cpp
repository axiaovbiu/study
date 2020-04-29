#define _CRT_SECURE_NO_WARNINGS 1

/*
������21. ��������˳��ʹ����λ��ż��ǰ��
����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ����������λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�



ʾ����

���룺nums = [1,2,3,4]
�����[1,3,2,4]
ע��[3,1,2,4] Ҳ����ȷ�Ĵ�֮һ��


��ʾ��

1 <= nums.length <= 50000
1 <= nums[i] <= 10000
*/

//˼·������˫ָ�룬startָ������ͷ��endָ������β��start��������end��ż������������

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