class Solution {
public:
	long long int result_globe[1001] = { 0 };
	long long int result_real[1001] = { 0 };

	int max(long long int a, long long int b) {
		if (a > b) return a;
		return b;
	}


	int cuttingRope(int n) {
		result_real[1] = 1;
		result_globe[1] = 1;
		for (int i = 2; i <= n; i++) {
			result_globe[i] = i;
			for (int j = 1; j <= i - 1; j++) {
				result_globe[i] = max(result_globe[i], result_globe[i - j] * (long long int)j);
				result_real[i] = max(result_real[i], result_globe[i - j] * (long long int)j);
			}
		}
		return result_real[n];
	}
};

int main() {
	Solution a;
	a.cuttingRope(10);
	return 0;
}