
int min(int a, int b)
{
	if (a < b) return a;
	return b;
}
class Solution {
	vector<int> min_price;
public:
	int maxProfit(vector<int>& prices) {
		for (int i = 0; i < prices.size(); i++)
		{
			if (i == 0) min_price.push_back(prices[0]);
			else
			{
				int new_min = min(prices[i], min_price[i - 1]);
				min_price.push_back(new_min);
			}
		}
		int max = 0;
		for (int i = 0; i < prices.size(); i++)
		{
			if (i != 0)
			{
				int current_max = prices[i] - min_price[i - 1];
				if (current_max > max) max = current_max;
			}
		}
		return max;
	}
};