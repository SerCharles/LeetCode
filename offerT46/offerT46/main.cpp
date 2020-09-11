#include<iostream>
#include<string>
using namespace std;

int result[33] = { 0 };
class Solution {
public:
	
	int translateNum(int num) {
		string num_string = to_string(num);
		result[0] = 1;
		for (int i = 1; i <= num_string.size(); i++)
		{
			//只把上一个数字翻译成字母
			result[i] = result[i - 1];
			if (i >= 2) {
				int number_1 = num_string.at(i - 2) - '0';
				int number_2 = num_string.at(i - 1) - '0';
				int number = number_1 * 10 + number_2;
				if (number >= 10 && number <= 25) {
					result[i] += result[i - 2];
				}
			}
		}
		return result[num_string.size()];
	}
};