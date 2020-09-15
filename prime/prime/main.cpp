#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
bool whether_divided[10001] = { 0 };
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
		while(j <= n)
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

void get_primes(int m)
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
		prime_sum[i] += current_num;
	}
}

int main()
{
	cin >> n;
	get_divided();
	for (int i = 2; i <= n; i++)
	{
		get_primes(i);
	}
	for (int i = 0; i < primes.size(); i++)
	{
		cout << primes[i] << " " << prime_sum[i] << endl;
	}
	return 0;
}