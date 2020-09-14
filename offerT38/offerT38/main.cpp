#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<string> permutation(string s) {
		vector<string> result;
		sort(s.begin(), s.end());
		result.push_back(s);
		string current = s;
		//找第一个顺序对，然后替换+排序
		while (1)
		{
			int i;
			bool success = 0;
			for (i = current.size() - 1; i >= 0; i--)
			{
				if (current[i] < current[i + 1])
				{	
					success = 1;
					break;
				}
			}
			if (!success) break;

			int min_place = i + 1;
			char min_item = current[i + 1];
			for (int j = i + 1; j < current.size(); j++)
			{
				if (current[j] < min_item && current[j] >current[i])
				{
					min_place = j;
					min_item = current[j];
				}
			}
			char temp = current[i];
			current[i] = current[min_place];
			current[min_place] = temp;

			current.begin();
			string::iterator a = current.begin();
			for (int j = 0; j < i + 1; j++) a++;
			sort(a, current.end());
			result.push_back(current);
		}
		return result;
	}
};


int main()
{
	Solution s;
	s.permutation("1453");
}