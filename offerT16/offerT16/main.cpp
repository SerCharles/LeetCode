class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0) return 1;
		else if (abs(n) % 2 == 1)
		{
			if (n > 0)
			{
				return myPow(x, n - 1) * x;
			}
			else
			{
				return myPow(x, n + 1) / x;
			}
		}
		else
		{
			double half = myPow(x, n / 2);
			return half * half;
		}
	}
};


int main()
{
	Solution s;
	s.myPow(2.00, -10);
}