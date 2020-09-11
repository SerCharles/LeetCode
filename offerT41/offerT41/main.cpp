#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

/** initialize your data structure here. */
struct small {
	bool operator ()  (int& a, int& b) {
		return a > b;
	}
};
struct big {
	bool operator ()  (int& a, int& b) {
		return a < b;
	}
};

class MedianFinder {
public:

	priority_queue<int, vector<int>, small> small_queue; //小顶堆，较大元素
	priority_queue<int, vector<int>, big> big_queue; //大顶堆，较小元素

	MedianFinder() {
		while (!small_queue.empty()) small_queue.pop();
		while (!big_queue.empty()) big_queue.pop();

	}

	void addNum(int num) {
		if (small_queue.empty()) {
			small_queue.push(num);
			return;
		}
		else if (big_queue.empty()) {
			int small_top = small_queue.top();
			if (small_top >= num)
			{
				big_queue.push(num);
			}
			else
			{
				small_queue.pop();
				small_queue.push(num);
				big_queue.push(small_top);
			}
			return;
		}


		int small_size = small_queue.size();
		int big_size = big_queue.size();
		int small_top = small_queue.top();
		int big_top = big_queue.top();

		//size 2情况：small多1或者一样多
		if (num >= small_top) {
			if (small_size == big_size) {
				small_queue.push(num);
			}
			else
			{
				small_queue.pop();
				small_queue.push(num);
				big_queue.push(small_top);
			}
		}
		else {
			if (small_size == big_size) {
				big_queue.push(num);
				int new_big_top = big_queue.top();
				big_queue.pop();
				small_queue.push(new_big_top);
			}
			else {
				big_queue.push(num);
			}
		}
	}

	double findMedian() {
		if (small_queue.empty()) {
			return 0;
		}
		else if (big_queue.empty()) {
			return small_queue.top();
		}
		int small_size = small_queue.size();
		int big_size = big_queue.size();
		int small_top = small_queue.top();
		int big_top = big_queue.top();
		if (small_size > big_size) {
			return double(small_top);
		}
		else {
			return (double(small_top + big_top) / 2.0);
		}

	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
	MedianFinder* obj = new MedianFinder();
	obj->addNum(1);
	obj->addNum(2);
	double param1 = obj->findMedian();
	obj->addNum(3);
	double param2 = obj->findMedian();
	cout << param1 << '\n' << param2;
}