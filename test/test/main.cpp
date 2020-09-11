#include<iostream>
#include<cmath>
using namespace std;
bool whether_divided[1000001] = { 0 };

void get_simple(int max)
{
	whether_divided[0] = 1;
	whether_divided[1] = 1;
	for (int i = 2; i <= sqrt(max); i++)
	{
		if (whether_divided[i] != 0) continue;
		int j = i;
		while (j <= max)
		{
			j += i;
			whether_divided[j] = 1;
		}

	}
}




int main()
{
	int min, max;
	cin >> min >> max;
	get_simple(max);
	int sum = 0;
	for (int i = min; i <= max - 2; i++)
	{
		if (whether_divided[i] == 0 && whether_divided[i + 2] == 0)
		{
			sum++;
		}
	}
	cout << sum;
	return 0;
}