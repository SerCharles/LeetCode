class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		vector<vector<int>> result;
		result.clear();
		int min = 2;
		int max = sqrt(2 * target);
		for (int i = max; i >= min; i--)
		{
			if ((target - (i - 1) * i / 2) % i == 0)
			{
				vector<int> this_result;
				this_result.clear();
				int start = (target - (i - 1) * i / 2) / i;
				for (int j = 0; j < i; j++)
				{
					this_result.push_back(j + start);
				}
				result.push_back(this_result);
			}
		}
		return result;
	}
};