#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int reversePairs(vector<int>& nums) {
		int sum = 0;
		if (nums.size() <= 1) return 0;
		sum = reverse_recursive(nums, 0, nums.size() - 1);
		return sum;
	}

	int reverse_recursive(vector<int>& nums, int start, int end) {
		int sum = 0;
		if (start >= end) return 0;
		int length = (end - start + 1) / 2;
		int result_front = reverse_recursive(nums, start, start + length - 1);
		int result_back = reverse_recursive(nums, start + length, end);
		int result_merge = get_merged_result(nums, start, start + length, end);
		sum = result_front + result_back + result_merge;
		return sum;
	}

	int get_merged_result(vector<int>& nums, int start, int middle, int end)
	{
		int sum = 0;
		vector<int> back_vector;
		back_vector.clear();
		for (int i = middle; i <= end; i++) back_vector.push_back(nums[i]);
		sort(back_vector.begin(), back_vector.end());
		for (int i = start; i < middle; i++)
		{
			int num = search_place(nums[i], back_vector);
			sum += num;
		}
		return sum;
	}

	int search_place(int num, vector<int>& list)
	{
		int start = 0;
		int end = list.size() - 1;
		while (start <= end)
		{
			int middle = (start + end) / 2;
			if (list[middle] < num)
			{
				start = middle + 1;
			}
			else
			{
				end = middle - 1;
			}
		}
		return start;
	}
};