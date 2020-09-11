int x[10] = { 0, 9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999 };
int f[10] = { 0, 1, 20, 300, 4000, 50000, 600000, 7000000, 80000000, 900000000 };
class Solution {
public:

	int countDigitOne(int n) {
		if (n == 0) return 0;
		if (n <= 9) return 1;
		if (n == 99) return 20;
		if (n == 999) return 300;
		if (n == 9999) return 4000;
		if (n == 99999) return 50000;
		if (n == 999999) return 600000;
		if (n == 9999999) return 7000000;
		if (n == 99999999) return 80000000;
		if (n == 999999999) return 900000000;
		int num = get_num(n);
		int front = get_front(n);
		int residue = n - front * (x[num] + 1);
		int bonus = 0;
		if (front == 1)
		{
			bonus = residue + 1;
		}
		else
		{
			bonus = x[num] + 1;
		}
		int result = f[num] * front + bonus + countDigitOne(residue);
		return result;
	}
	int get_num(int n) {
		int num = 0;
		while (n >= 10)
		{
			n = n / 10;
			num++;
		}
		return num;
	}

	int get_front(int n) {
		while (n >= 10)
		{
			n = n / 10;
		}
		return n;
	}
};