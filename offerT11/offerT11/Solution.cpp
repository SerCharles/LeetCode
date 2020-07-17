#include<vector>
using namespace std;

class Solution {
public:
	int minArray(vector<int>& numbers) {
		int head = 0;
		int tail = numbers.size() - 1;
		while (head <= tail) {
			int middle = (head + tail) / 2;
			if (numbers[middle] < numbers[tail]) {
				tail = middle;
			}
			else if (numbers[middle] > numbers[tail]) {
				head = middle + 1;
			}
			else {
				tail--;
			}
		}
		return numbers[head];
	}
};