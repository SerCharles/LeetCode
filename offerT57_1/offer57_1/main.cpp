class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result;
		result.clear();
		for (int i = 0; i < nums.size(); i++)
		{
			int other = target - nums[i];
			if (binary_search(nums, other))
			{
				result.push_back(nums[i]);
				result.push_back(other);
				return result;
			}
		}
		return result;
	}
	bool binary_search(vector<int>& nums, int target) {
		int start = 0;
		int end = nums.size() - 1;
		while (start <= end)
		{
			int middle = (start + end) / 2;
			if (target == nums[middle]) return 1;
			else if (target < nums[middle])
			{
				end = middle - 1;
			}
			else
			{
				start = middle + 1;
			}
		}
		return 0;
	}
};