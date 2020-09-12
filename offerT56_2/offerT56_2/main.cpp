#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int result = 0;
		for (int i = 0; i < 32; i++)
		{
			int indice = 1 << i;
			int sum = 0;
			for (int j = 0; j < nums.size(); j++)
			{
				if (indice & nums[j]) sum++;
			}
			if (sum % 3 != 0) {
				result = result | indice;
			}
		}
		return result;
	}
};