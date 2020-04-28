#define _CRT_SECURE_NO_WARNINGS 1

/*
������11. ��ת�������С����
��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
����һ����������������һ����ת�������ת�������СԪ�ء�
���磬���� [3,4,5,1,2] Ϊ [1,2,3,4,5] ��һ����ת�����������СֵΪ1��

ʾ�� 1��

���룺[3,4,5,1,2]
�����1
ʾ�� 2��

���룺[2,2,2,0,1]
�����0
*/


//˼·��������ת�������ԣ�����Сֵ�������Ϊ�������������飬�������ֵ�����ڵ����������ֵ��
//����˫ָ��i,j���ֱ�ָ�����������ͷβ�����м�ֵnumbers[mid], ��numbers[mid] >= numbers[i],��mid
//�������飬������ָ��i,��numbers[mid] <= numbers[j],��mid�������飬������ָ��j�����jָ����Сֵ��
//iָ����Сֵ��ǰһ������j-i == 1ʱΪѭ������������ʱ�临�Ӷ�O(logN)

//���������{1,1,0,1,1,1} {1,1,1,1,0,1},numbers[i]=numbers[j]=number[mid],˳����ң��˻�ΪO(N)

class Solution {
public:
	int minArray(vector<int>& numbers) {
		int i = 0;
		int j = numbers.size() - 1;
		//��������ת����ԭ������ͬ�����һ��Ԫ�ؾ�����Сֵ
		int mid = i;

		while (numbers[i] >= numbers[j])
		{
			//jָ������Ԫ�أ�iָ����ǰһ��Ԫ�أ���ֵΪ1���򷵻ؽ��
			if (j - i == 1)
			{
				mid = j;
				break;
			}

			mid = (i + j) >> 1;

			//����������i��j��midָ���Ԫ����ͬ�����޷��ж�mid�����ĸ������飬˳�����
			if (numbers[i] == numbers[mid] && numbers[mid] == numbers[j])
				return InOrder(numbers, i, j);

			//�����߽�
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
������15. ��������1�ĸ���
��ʵ��һ������������һ��������������������Ʊ�ʾ�� 1 �ĸ��������磬�� 9 ��ʾ�ɶ������� 1001���� 2 λ�� 1����ˣ�������� 9����ú������ 2��

ʾ�� 1��

���룺00000000000000000000000000001011
�����3
���ͣ�����Ķ����ƴ� 00000000000000000000000000001011 �У�������λΪ '1'��
ʾ�� 2��

���룺00000000000000000000000010000000
�����1
���ͣ�����Ķ����ƴ� 00000000000000000000000010000000 �У�����һλΪ '1'��
ʾ�� 3��

���룺11111111111111111111111111111101
�����31
���ͣ�����Ķ����ƴ� 11111111111111111111111111111101 �У����� 31 λΪ '1'��
*/


//˼·��n &= (n - 1) ��ֱ��nΪ0��ѭ��������Ϊ1�ĸ���
//���磺1100 --->   1100 & 1011 = 1000
//					1000 & 0111 == 0000  ѭ������


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
������16. ��ֵ�������η�
ʵ�ֺ���double Power(double base, int exponent)����base��exponent�η�������ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ������⡣



ʾ�� 1:

����: 2.00000, 10
���: 1024.00000
ʾ�� 2:

����: 2.10000, 3
���: 9.26100
ʾ�� 3:

����: 2.00000, -2
���: 0.25000
����: 2-2 = 1/22 = 1/4 = 0.25
*/



//˼·��1.�жϵ����Ƿ�Ϊ0��������Ϊ0��ָ��Ϊ��������0�󵼻�ʹ�������
//		2.��ָ��Ϊ��������ָ��ȡ�����Խ���󵼼���
//		3.����η�ʱ�����ʹ��������ˣ�ʱ�临�Ӷ���O(N),��ʹ�ÿ������㷨
//		4.�������㷨��ʹ�á�����˼�롱��3^5�η����Կ�Ϊ3 * 3^4��3^4�ֿ��Կ�Ϊ3^2 * 3^2, 3^2���Կ��� 3^1 * 3^1
//		��������ʱ�临�Ӷ���O(longN)
class Solution {
public:
	double myPow(double x, int n) {
		//���xΪ0��nΪ�������󵼻ᵼ�³������
		if (x - 0.0 < 0.000000001 && x - 0.0 > -0.000000001)
			return 0;

		//letcode�ӣ��������long���վͻ����
		long exp = n;
		//���nΪ������ȡ������
		if (exp < 0)
		{
			exp = -exp;
			x = 1.0 / x;
		}

		double res = 1.0;

		//�������㷨
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
������17. ��ӡ��1������nλ��
�������� n����˳���ӡ���� 1 ������ n λʮ���������������� 3�����ӡ�� 1��2��3 һֱ������ 3 λ�� 999��

ʾ�� 1:

����: n = 1
���: [1,2,3,4,5,6,7,8,9]
*/


//˼·��������ת��Ϊ����

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

			//�н�λ
			if (sum >= 10)
			{
				//���λ�н�λ
				if (i == 0)
				{
					IsOverFlow = true;
					break;
				}
				//���λ�޽�λ
				else
				{
					sum -= 10;
					taken = 1;
					number[i] = '0' + sum;
				}
			}
			//�޽�λ
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
������18. ɾ������Ľڵ�
�������������ͷָ���һ��Ҫɾ���Ľڵ��ֵ������һ������ɾ���ýڵ㡣

����ɾ����������ͷ�ڵ㡣

ע�⣺����Ա�ԭ���иĶ�

ʾ�� 1:

����: head = [4,5,1,9], val = 5
���: [4,1,9]
����: ������������ֵΪ 5 �ĵڶ����ڵ㣬��ô�ڵ�������ĺ���֮�󣬸�����Ӧ��Ϊ 4 -> 1 -> 9.
ʾ�� 2:

����: head = [4,5,1,9], val = 1
���: [4,5,9]
����: ������������ֵΪ 1 �ĵ������ڵ㣬��ô�ڵ�������ĺ���֮�󣬸�����Ӧ��Ϊ 4 -> 5 -> 9.
*/

class Solution {
public:
	ListNode* deleteNode(ListNode* head, int val) {
		if (head == nullptr)
			return nullptr;
		//�����������
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


//���ʹ��O(1)ʱ�临�Ӷȣ�ɾ��ĳ�����
//˼·�����ɾ����㲻��β��㣬���ҵ���ɾ��������һ����㣬����һ����㸲�Ǵ�ɾ����㣬ʱ�临�Ӷ���O(1)
//		�������ֻ��һ���ڵ㣨����ͷ�������β��㣩��ֱ��ɾ�����ÿգ�
//		���ɾ�������β��㣬˳�����ɾ����ʱ�临�Ӷ�O(N),��ƽ��ʱ�临�Ӷ���O(1)

class Solution {
public:
	ListNode* deleteNode(ListNode* head, ListNode *pos){

		if (head == nullptr || pis == nullptr)
			return nullptr;

		//����β���
		if (pos->next)
		{
			ListNode *next = pos->next;
			pos->val = next->val;
			pos->next = next->next;
		}
		//ֻ��һ���ڵ�
		else if (head->next == nullptr)
		{
			delete pos;
			pos = nullptr;
			head = nullptr;
		}
		//��β���
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