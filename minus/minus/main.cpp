#include<iostream>
#include<string>
#include<cstring>
using namespace std;

char b[10086] = { 0 };
char a[10086] = { 0 };
char result[10086] = { 0 };

int compare(char a[], char b[]);
int minus(char a[], char b[], char result[]);


//a´ó1 aĞ¡-1 =0
int compare(char a[], char b[])
{
	int len_a = strlen(a);
	int len_b = strlen(b);
	if (len_a < len_b)
	{
		return -1;
	}
	else if (len_a > len_b)
	{
		return 1;
	}
	else
	{
		for (int i = 0; i < len_a; i++)
		{
			if (a[i] < b[i])
			{
				return -1;
			}
			else if (a[i] > b[i])
			{
				return 1;
			}
		}
	}
	return 0;
}



//a > b
int my_minus(char a[], char b[], char result[])
{
	int len = 0;
	int max_len = strlen(a);
	int min_len = strlen(b);
	for (int i = 0; i < max_len; i++)
	{
		char num_1 = a[max_len - 1 - i];
		char num_2 = '0';
		if (i < min_len)
		{
			num_2 = b[min_len - 1 - i];
		}
		int nova = num_1 - num_2;
		if (nova < 0)
		{
			nova += 10;
			a[max_len - i - 2] -= 1;
		}
		result[len] = '0' + nova;
		len++;
	}
	return len;
}

void print_ans(char result[], int len)
{
	bool whether_zero = 1;
	for (int i = len - 1; i >= 0; i--)
	{
		if (whether_zero == 1)
		{
			if (result[i] != '0')
			{
				whether_zero = 0;
			}
		}
		if (whether_zero != 1)
		{
			cout << result[i];
		}
	}
}

int main()
{
	cin >> a;
	cin >> b;
	int r = compare(a, b);
	if (r == 0)
	{
		cout << '0';
	}
	else if (r == 1)
	{
		int len = my_minus(a, b, result);
		print_ans(result, len);
	}
	else
	{
		cout << '-';
		int len = my_minus(b, a, result);
		print_ans(result, len);
	}
	return 0;
}