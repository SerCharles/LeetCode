class Solution {
public:
	int answer_list[101] = { 0 };
	int fib(int n) {
		if (n == 0) {
			answer_list[0] = 0;
			return 0;
		}
		else if (n == 1) {
			answer_list[1] = 1;
			return 1;
		}
		else {
			if (answer_list[n] != 0) {
				return answer_list[n];
			}
			else {
				int ans = (fib(n - 2) + fib(n - 1)) % 1000000007;
				answer_list[n] = ans;
				return ans;
			}
		}

	}
};

