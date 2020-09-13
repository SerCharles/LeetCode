#include<iostream>
#include<vector>
using namespace std;



int main()
{
	int n = 0, m = 0, s = 0;
	vector<vector<int> > ends;
	vector<vector<int> > lengths;
	vector<int> min_dists;
	vector<bool> visits;
	int max = ~(1 << 31);
	ends.clear();
	lengths.clear();
	min_dists.clear();
	visits.clear();
	vector<int> empty;
	empty.clear();
	cin >> n >> m >> s;
	for (int i = 0; i <= n; i++)
	{
		ends.push_back(empty);
		lengths.push_back(empty);
		min_dists.push_back(max);
		visits.push_back(0);
	}
	for (int i = 0; i < m; i++)
	{
		int start = 0, end = 0, length = max;
		cin >> start >> end >> length;
		ends[start].push_back(end);
		lengths[start].push_back(length);
	}

	min_dists[s] = 0;
	for (int j = 1; j <= n; j++)
	{
		int current = 0;
		int min_dist = max;
		for (int i = 1; i <= n; i++)
		{
			if (visits[i] == 0 && min_dists[i] < min_dist)
			{
				current = i;
				min_dist = min_dists[i];
			}
		}
		
		for (int i = 0; i < ends[current].size(); i++)
		{
			int end = ends[current][i];
			int length = lengths[current][i];
			int old_dist = min_dists[end];
			int new_dist = length + min_dists[current];
			if (new_dist < old_dist)
			{
				min_dists[end] = new_dist;
			}
		}
		visits[current] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		cout << min_dists[i] << ' ';
	}
}