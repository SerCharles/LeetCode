class Solution {
public:
	int power[20] = { 0 };
	bool isPowerOfThree(int n) {
		for (int i = 0; i < 20; i++) get_power(i);
		for (int i = 0; i < 20; i++)
		{
			if (power[i] == n) return 1;
		}
		return 0;
	}
	int get_power(int num)
	{
		if (num == 0)
		{
			power[0] = 1;
			return 1;
		}
		if (power[num] != 0) return power[num];
		if (num % 2 == 1)
		{
			int result = get_power(num - 1) * 3;
			power[num] = result;
			return result;
		}
		else
		{
			int half = get_power(num / 2);
			int result = half * half;
			power[num] = result;
			return result;
		}
	}

};