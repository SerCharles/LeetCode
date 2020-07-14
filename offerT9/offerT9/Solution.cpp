#include <stack>

class CQueue {
public:
	std::stack<int> stackMain;
	std::stack<int> stackBack;

	CQueue() {
		while (!stackMain.empty()) 
		{
			stackMain.pop();
		}
		while (!stackBack.empty())
		{
			stackBack.pop();
		}
	}

	void appendTail(int value) 
	{
		stackMain.push(value);
	}

	int deleteHead() 
	{
		while (!stackMain.empty()) 
		{
			int num = stackMain.top();
			stackMain.pop();
			stackBack.push(num);
		}
		if (!stackBack.empty())
		{
			int result = stackBack.top();
			stackBack.pop();

			while (!stackBack.empty()) {
				int num = stackBack.top();
				stackBack.pop();
				stackMain.push(num);
			}
			return result;
		}
		else
		{
			return -1;
		}
	}
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */