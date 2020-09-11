#include<iostream>
using namespace std;

class Solution {
public:
	int range_num[9];
	int border_num[9];
	int findNthDigit(int n) {
		if (n < 10) return n;
		range_num[0] = 0;
		border_num[0] = 0;
		int old_tenth = 0;
		int tenth = 10;
		for (int i = 1; i < 9; i++)
		{
			range_num[i] = range_num[i - 1] + i * (tenth - old_tenth);
			if (old_tenth == 0) old_tenth = 10;
			else old_tenth *= 10;
			if (i == 1) border_num[i] = 10;
			else border_num[i] = border_num[i - 1] * 10;
			tenth *= 10;
		}
		int num_numbers = 1;
		for (num_numbers = 1; num_numbers < 9; num_numbers++)
		{
			if (n < range_num[num_numbers] - 1) break;
		}
		int bias = n - range_num[num_numbers - 1] + 1;
		int bias_num = (bias - 1) / num_numbers;
		int num_in_number = (bias + num_numbers - 1) % num_numbers;
		int the_number = border_num[num_numbers - 1] + bias_num;
		int result = find_digit_in_number(the_number, num_in_number, num_numbers);
		return result;
	}
	int find_digit_in_number(int number, int num_in_number, int total_num) {
		int times = total_num - 1 - num_in_number;
		for (int i = 0; i < times; i++) {
			number /= 10;
		}
		int result = number % 10;
		return result;
	}
};

int main() {
	Solution solution;
	cout << solution.findNthDigit(11);
}