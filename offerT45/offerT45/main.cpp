#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;



class Solution {
public:
	bool compare(int a, int b) {
		string new_1 = "" + to_string(a) + to_string(b);
		string new_2 = "" + to_string(b) + to_string(a);
		return new_1 <= new_2;
	}
	string minNumber(vector<int>& nums) {
		//sort(begin(nums), end(nums), compare);
		for (int i = 1; i < nums.size(); i++) {
			for (int j = 0; j < i; j++) {
				if (compare(nums[i], nums[j])) {
					int temp = nums[i];
					nums[i] = nums[j];
					nums[j] = temp;
				}
			}
		}
		string result = "";
		for (int i = 0; i < nums.size(); i++) {
			result += to_string(nums[i]);
		}
		return result;
	}
};