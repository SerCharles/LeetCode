class Solution {
public:
	int hammingWeight(uint32_t n) {
		uint32_t a = n;
		int sum = 0;


		while (a != 0) {
			sum += a & 1;
			a = a >> 1;
		}
		return sum;
	}
};

int main() {

}