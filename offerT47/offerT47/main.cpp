int result[200][200] = { 0 };
int max(int a, int b)
{
	if (a > b) return a;
	return b;
}
class Solution {
public:
	
	int maxValue(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++) {
				int result_i = 0;
				if (i > 0) result_i = result[i - 1][j];
				int result_j = 0;
				if (j > 0) result_j = result[i][j - 1];
				result[i][j] = max(result_i, result_j) + grid[i][j];
			}
		}
		return result[m - 1][n - 1];
	}
};