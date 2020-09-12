class Solution {
public:
	vector<int> sum_front;
	vector<int> sum_back;
	vector<int> constructArr(vector<int>& a) {
		sum_front.clear();
		sum_back.clear();
		vector<int> result;
		result.clear();
		if (a.size() == 0) return result;
		if (a.size() == 1)
		{
			result.push_back(1);
			return result;
		}
		for (int i = 0; i < a.size(); i++)
		{
			if (i == 0) sum_front.push_back(a[i]);
			else
			{
				int nova = a[i] * sum_front[i - 1];
				sum_front.push_back(nova);
			}
		}
		for (int i = a.size() - 1; i >= 0; i--)
		{
			if (i == a.size() - 1) sum_back.push_back(a[i]);
			else
			{
				int nova = a[i] * sum_back[sum_back.size() - 1];
				sum_back.push_back(nova);
			}
		}
		for (int i = 0; i < a.size(); i++)
		{
			int sum = 0;
			if (i == 0)
			{
				sum = sum_back[a.size() - 2];
			}
			else if (i == a.size() - 1)
			{
				sum = sum_front[a.size() - 2];
			}
			else
			{
				sum = sum_front[i - 1] * sum_back[a.size() - i - 2];
			}
			result.push_back(sum);
		}
		return result;
	}
};