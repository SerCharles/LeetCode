#include<iostream>
#include<vector>
#include<string>
using namespace std;

int max_num[1001][1001] = { 0 };
int a[1001] = { 0 };
int b[1001] = { 0 };
int n;


int max(int a, int b)
{
	if (a > b) return a;
	return b;
}

int max(int a, int b, int c)
{
	if (a > b && a > c) return a;
	if (b > c) return b;
	return c;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (a[i] == b[j]) max_num[i][j] = max(max_num[i - 1][j], max_num[i][j - 1], max_num[i - 1][j - 1] + 1);
			else max_num[i][j] = max(max_num[i - 1][j], max_num[i][j - 1]);
		}
	}
	cout << max_num[n][n];
	return 0;
}