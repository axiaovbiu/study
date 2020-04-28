#define _CRT_SECURE_NO_WARNINGS 1

/*
面试题11. 旋转数组的最小数字
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。

示例 1：

输入：[3,4,5,1,2]
输出：1
示例 2：

输入：[2,2,2,0,1]
输出：0
*/


//思路：根据旋转数组特性，以最小值将数组分为左右两个子数组，左数组的值都大于等于右数组的值，
//定义双指针i,j，分别指向整个数组的头尾，求中间值numbers[mid], 若numbers[mid] >= numbers[i],则mid
//在左数组，收缩左指针i,若numbers[mid] <= numbers[j],则mid在右数组，收缩右指针j，最后，j指向最小值，
//i指向最小值的前一个，即j-i == 1时为循环结束条件，时间复杂度O(logN)

//特殊情况：{1,1,0,1,1,1} {1,1,1,1,0,1},numbers[i]=numbers[j]=number[mid],顺序查找，退化为O(N)

class Solution {
public:
	int minArray(vector<int>& numbers) {
		int i = 0;
		int j = numbers.size() - 1;
		//若数组旋转后与原数组相同，则第一个元素就是最小值
		int mid = i;

		while (numbers[i] >= numbers[j])
		{
			//j指向所求元素，i指向其前一个元素，差值为1，则返回结果
			if (j - i == 1)
			{
				mid = j;
				break;
			}

			mid = (i + j) >> 1;

			//特殊情况如果i，j，mid指向的元素相同，则无法判断mid属于哪个子数组，顺序遍历
			if (numbers[i] == numbers[mid] && numbers[mid] == numbers[j])
				return InOrder(numbers, i, j);

			//收缩边界
			if (numbers[mid] >= numbers[i])
				i = mid;
			else if (numbers[mid] <= numbers[j])
				j = mid;
		}

		return numbers[mid];

	}

	int InOrder(vector<int> &num, int start, int end)
	{
		int ret = num[start];
		for (int i = start + 1; i <= end; i++)
		{
			if (ret > num[i])
				ret = num[i];
		}
		return ret;
	}
};


/*
面试题15. 二进制中1的个数
请实现一个函数，输入一个整数，输出该数二进制表示中 1 的个数。例如，把 9 表示成二进制是 1001，有 2 位是 1。因此，如果输入 9，则该函数输出 2。

示例 1：

输入：00000000000000000000000000001011
输出：3
解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。
示例 2：

输入：00000000000000000000000010000000
输出：1
解释：输入的二进制串 00000000000000000000000010000000 中，共有一位为 '1'。
示例 3：

输入：11111111111111111111111111111101
输出：31
解释：输入的二进制串 11111111111111111111111111111101 中，共有 31 位为 '1'。
*/


//思路：n &= (n - 1) ，直到n为0，循环次数即为1的个数
//例如：1100 --->   1100 & 1011 = 1000
//					1000 & 0111 == 0000  循环两次


class Solution {
public:
	int hammingWeight(uint32_t n) {
		int count = 0;


		while (n)
		{
			n &= (n - 1);
			count++;
		}
		return count;
	}
};



/*
面试题16. 数值的整数次方
实现函数double Power(double base, int exponent)，求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。



示例 1:

输入: 2.00000, 10
输出: 1024.00000
示例 2:

输入: 2.10000, 3
输出: 9.26100
示例 3:

输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
*/



//思路：1.判断底数是否为0，若底数为0，指数为负数，对0求导会使程序崩溃
//		2.若指数为负数，则将指数取反，对结果求导即可
//		3.计算次方时，如果使用线性相乘，时间复杂度是O(N),可使用快速幂算法
//		4.快速幂算法，使用“二分思想”，3^5次方可以看为3 * 3^4，3^4又可以看为3^2 * 3^2, 3^2可以看成 3^1 * 3^1
//		依次类推时间复杂度是O(longN)
class Solution {
public:
	double myPow(double x, int n) {
		//如果x为0，n为负数，求导会导致程序崩溃
		if (x - 0.0 < 0.000000001 && x - 0.0 > -0.000000001)
			return 0;

		//letcode坑，如果不用long接收就会溢出
		long exp = n;
		//如果n为负数，取反，求导
		if (exp < 0)
		{
			exp = -exp;
			x = 1.0 / x;
		}

		double res = 1.0;

		//快速幂算法
		while (exp)
		{
			if (exp & 0x1)
				res *= x;
			x *= x;
			exp >>= 1;
		}
		return res;

	}
};



/*
面试题17. 打印从1到最大的n位数
输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

示例 1:

输入: n = 1
输出: [1,2,3,4,5,6,7,8,9]
*/


//思路：将大数转换为整数

class Solution {
public:
	vector<int> ret;
	vector<int> printNumbers(int n) {
		if (n <= 0)
			return ret;

		string number(n, '0');
		while (!Increment(number))
		{
			Print(number);
		}

		return ret;
	}

	bool Increment(string &number)
	{
		int taken = 0;
		bool IsOverFlow = false;

		int numLen = number.size();
		int sum;

		for (int i = numLen - 1; i >= 0; i--)
		{
			sum = number[i] - '0' + taken;
			if (i == numLen - 1)
				sum++;

			//有进位
			if (sum >= 10)
			{
				//最高位有进位
				if (i == 0)
				{
					IsOverFlow = true;
					break;
				}
				//最高位无进位
				else
				{
					sum -= 10;
					taken = 1;
					number[i] = '0' + sum;
				}
			}
			//无进位
			else
			{
				number[i] = '0' + sum;
				break;
			}
		}
		return IsOverFlow;
	}

	void Print(string str)
	{
		string cur;
		bool IsBeginning0 = true;
		auto it = str.begin();

		while (it != str.end())
		{
			if (IsBeginning0 && *it != '0')
				IsBeginning0 = false;

			if (!IsBeginning0)
			{
				cur += *it;
			}
			it++;
		}

		int tmp = stoi(cur);
		ret.push_back(tmp);
	}
};



/*
面试题18. 删除链表的节点
给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。

返回删除后的链表的头节点。

注意：此题对比原题有改动

示例 1:

输入: head = [4,5,1,9], val = 5
输出: [4,1,9]
解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
示例 2:

输入: head = [4,5,1,9], val = 1
输出: [4,5,9]
解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
*/

class Solution {
public:
	ListNode* deleteNode(ListNode* head, int val) {
		if (head == nullptr)
			return nullptr;
		//创建辅助结点
		ListNode *phead = new ListNode(0);
		phead->next = head;
		ListNode *cur = phead;
		while (cur->next)
		{
			if (cur->next->val == val)
				cur->next = cur->next->next;
			else
				cur = cur->next;
		}
		return phead->next;
	}
};


//如果使用O(1)时间复杂度，删除某个结点
//思路：如果删除结点不是尾结点，则找到待删除结点的下一个结点，用下一个结点覆盖待删除结点，时间复杂度是O(1)
//		如果链表只有一个节点（既是头结点又是尾结点），直接删除，置空，
//		如果删除结点是尾结点，顺序查找删除，时间复杂度O(N),即平均时间复杂度是O(1)

class Solution {
public:
	ListNode* deleteNode(ListNode* head, ListNode *pos){

		if (head == nullptr || pis == nullptr)
			return nullptr;

		//不是尾结点
		if (pos->next)
		{
			ListNode *next = pos->next;
			pos->val = next->val;
			pos->next = next->next;
		}
		//只有一个节点
		else if (head->next == nullptr)
		{
			delete pos;
			pos = nullptr;
			head = nullptr;
		}
		//是尾结点
		else
		{
			ListNode *cur = head;
			while (cur->next != pos)
			{
				cur = cur->next;
			}
			cur->next = nullptr;
			delete pos;
			pos = nullptr;
		}
	}
};