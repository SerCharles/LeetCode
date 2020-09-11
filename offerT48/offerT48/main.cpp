#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;


set<int> whether_true;
vector<int> ugly_number;
class Solution {
public:
	int nthUglyNumber(int n) {
		ugly_number.clear();
		whether_true.clear();
		ugly_number.push_back(1);
		whether_true.insert(1);
		int sum = 1;
		int i = 2;
		while (sum < n)
		{
			if (i % 2 == 0 && whether_true.find(i / 2) != end(whether_true)) {
				whether_true.insert(i);
				ugly_number.push_back(i);
				sum++;
			}
			else if (i % 3 == 0 && whether_true.find(i / 3) != end(whether_true)) {
				whether_true.insert(i);
				ugly_number.push_back(i);
				sum++;
			}
			else if (i % 5 == 0 && whether_true.find(i / 5) != end(whether_true)) {
				whether_true.insert(i);
				ugly_number.push_back(i);
				sum++;
			}
			i++;
		}
		return ugly_number[n - 1];
	}
};

int main()
{
	Solution solution;
	cout << solution.nthUglyNumber(10);
}