#include<iostream>
#include<string>
#include<vector>
using namespace std;
int pi[100000] = { 0 };
string base_str;
string main_str;


void get_pi()
{
	pi[0] = -1;
	int p = -1;
	for (int i = 1; i < base_str.size(); i++)
	{
		while (p >= 0 && base_str[p + 1] != base_str[i])
		{
			p = pi[p];
		}
		if (base_str[p + 1] == base_str[i])
		{
			p++;
		}
		pi[i] = p;
		
	}
}

int main()
{
	cin >> main_str;
	cin >> base_str;
	get_pi();
	vector<int> results;
	results.clear();
	int p = -1;
	for (int i = 0; i < main_str.size(); i++)
	{
		while (p >= 0 && base_str[p + 1] != main_str[i])
		{
			p = pi[p];
		}
		if (base_str[p + 1] == main_str[i])
		{
			if (p + 1 == base_str.size() - 1)
			{
				int front = i - base_str.size() + 2;
				results.push_back(front);
				p = pi[p];
			}
			p++;
		}

	}
	for (int i = 0; i < results.size(); i++) cout << results[i] << endl;
	for (int i = 0; i < base_str.size(); i++) cout << pi[i] + 1 << " ";
	return 0;
}