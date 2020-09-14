#include<iostream>
#include<string>
using namespace std;

int pi[100000] = { 0 };
string base_str;
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
	int m, k;
	cin >> m >> k;
	cin >> base_str;
	get_pi();
	string result = "";
	int sum = 0;
	int i = 0;
	while (sum < k)
	{
		result.push_back(base_str[i]);
		if (i == base_str.size() - 1)
		{
			sum++;
			i = pi[i];
		}
		i++;
	}
	cout << result;
	return 0;
}