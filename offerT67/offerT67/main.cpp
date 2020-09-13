#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	int min = 1 << 31;
	int max = ~(1 << 31);
	long long int max_positive = max;
	long long int min_positive = max_positive + 1;

	int strToInt(string str) {
		int start_flag = 0;
		bool sign = 1;

		//去空格
		while (start_flag < str.size() && str[start_flag] == ' ')
		{
			start_flag++;
		}
		if (start_flag >= str.size() || (str[start_flag] != '+' && str[start_flag] != '-'
			&& (str[start_flag] < '0' || str[start_flag] > '9')))
		{
			return 0;
		}

		//判断符号
		if (str[start_flag] == '+') start_flag++;
		else if (str[start_flag] == '-')
		{
			sign = 0;
			start_flag++;
		}

		//找数字部分
		int end_flag = start_flag;
		for (end_flag = start_flag; end_flag < str.size(); end_flag++)
		{
			if (str[end_flag] < '0' || str[end_flag] > '9') break;
		}
		end_flag -= 1;
		if (end_flag < start_flag) return 0;

		//找第一个不是0的字符
		while (start_flag <= end_flag)
		{
			if (str[start_flag] != '0') break;
			start_flag++;
		}
		if (end_flag < start_flag) return 0;

		//字符-数字
		int result = get_int(str, start_flag, end_flag, sign);
		return result;
	}

	int get_int(string str, int start, int end, bool sign)
	{
		int length = end - start + 1;
		//长度>10 必然越界
		if (length > 10)
		{
			if (sign) return max;
			else return min;
		}

		long long int sum = 0;
		int tenth = 1;
		for (int i = 0; i < length; i++)
		{
			int char_num = str[end - i] - '0';
			long long int the_char_num = 0 + char_num;
			long long int the_tenth = 0 + tenth;
			long long int current = the_char_num * the_tenth;
			sum += current;
			if (i < 9) tenth *= 10;
		}
		if (sign == 1 && sum >= max_positive) return max;
		if (sign == 0 && sum >= min_positive) return min;

		int result = 0;
		if (sign == 0) result = -sum;
		else result = sum;
		return result;
	}
};

int main()
{
	Solution solution;
	cout << solution.strToInt("    -0042") << endl;
	cout << solution.strToInt("4193 with words") << endl;
}