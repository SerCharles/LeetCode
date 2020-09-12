class MaxQueue {
public:
	deque<int> the_deque;
	queue<int> the_queue;
	MaxQueue() {
		while (!the_queue.empty()) the_queue.pop();
		while (!the_deque.empty()) the_deque.pop_back();

	}

	int max_value() {
		if (!the_deque.empty()) return the_deque.front();
		else return -1;
	}

	void push_back(int value) {
		while (!the_deque.empty() && value > the_deque.back()) the_deque.pop_back();
		the_queue.push(value);
		the_deque.push_back(value);
	}

	int pop_front() {
		if (the_queue.empty()) return -1;
		int num = the_queue.front();
		if (num == the_deque.front()) the_deque.pop_front();
		the_queue.pop();
		return num;
	}
};

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		MaxQueue the_queue;
		vector<int> result;
		result.clear();
		if (nums.empty()) return result;
		for (int i = 0; i < k; i++) {
			the_queue.push_back(nums[i]);
		}
		for (int i = 0; i <= nums.size() - k; i++) {
			int max = the_queue.max_value();
			result.push_back(max);
			if (i != nums.size() - k)
			{
				the_queue.pop_front();
				the_queue.push_back(nums[k + i]);
			}
		}
		return result;
	}
};