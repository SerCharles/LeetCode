class Solution {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		vector<int> result;
		result.clear();
		for (int i = 0; i < 32; i++) {
			int indice = 1 << i;
			int sum_1 = 0;
			int sum_0 = 0;
			for (int j = 0; j < nums.size(); j++)
			{
				if (indice & nums[j])
				{
					sum_1 = sum_1 ^ nums[j];
				}
				else
				{
					sum_0 = sum_0 ^ nums[j];
				}
			}
			if (sum_1 != 0 && sum_0 != 0)
			{
				result.push_back(sum_1);
				result.push_back(sum_0);
				return result;
			}
		}
		return result;
	}
};