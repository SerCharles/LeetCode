#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
bool whether_divided[100001] = { 0 };
vector<int> primes;
vector<int> prime_sum;
int n;
void get_divided()
{
	primes.clear();
	prime_sum.clear();
	whether_divided[0] = 1;
	whether_divided[1] = 1;
	for (int i = 2; i <= sqrt(n); i++)
	{
		int j = 2 * i;
		if (whether_divided[i] == 1) continue;
		while (j <= n)
		{
			whether_divided[j] = 1;
			j += i;
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (whether_divided[i] == 0)
		{
			primes.push_back(i);
			prime_sum.push_back(0);
		}
	}
}

vector<int> get_primes(int m)
{
	vector<int> result;
	result.clear();
	for (int i = 0; i < primes.size(); i++)
	{
		int current_num = 0;
		while (m % primes[i] == 0)
		{
			current_num++;
			m = m / primes[i];
		}
		result.push_back(current_num);
	}
	return result;
}

int get_choose(int up, int down)
{
	if (down > (up / 2)) down = up - down;
	int sum_down = 1;
	int sum_up = 1;
	for (int i = 0; i < down; i++)
	{
		sum_up *= (up - i);
		sum_down *= (i + 1);
	}
	return sum_up / sum_down;

}

int main()
{
	int min, max;
	cin >> min >> max;
	if (max % min != 0)
	{
		cout << 0;
		return 0;
	}
	else if (max == min)
	{
		cout << 1;
		return 0;
	}
	n = max / min;
	get_divided();
	vector<int> result_primes = get_primes(n);
	int num_primes = 0;
	for (int i = 0; i < result_primes.size(); i++)
	{
		if (result_primes[i] != 0) num_primes++;
	}
	int sum = 0;
	for (int i = 1; i < num_primes; i++)
	{
		sum += get_choose(num_primes, i);
	}
	sum += 2;
	cout << sum;
	return 0;
}