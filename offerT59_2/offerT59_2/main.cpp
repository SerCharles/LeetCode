#include<iostream>
#include<deque>
#include<queue>
using namespace std;


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

int main(){
	MaxQueue* obj = new MaxQueue();
	cout<<obj->max_value()<<endl;
	obj->push_back(1);
	obj->push_back(2);
	cout << obj->max_value() << endl;
	cout << obj->pop_front() << endl;
	cout << obj->max_value() << endl;
}