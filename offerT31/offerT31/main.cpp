#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		vector<int> current_stack;
		int length = pushed.size();
		int flag_a = 0;
		int flag_b = 0;
		while (flag_b < length)
		{
			int stack_size = current_stack.size();

			//空，只能进
			if (stack_size == 0)
			{
				current_stack.push_back(pushed[flag_a]);
				flag_a++;
				continue;
			}
			int stack_top = current_stack[stack_size - 1];
			//栈顶和你要pop的一样，退栈
			if (stack_top == popped[flag_b])
			{
				current_stack.pop_back();
				flag_b++;
				continue;
			}
			else
			{
				//失败
				if (flag_a >= length)
				{
					return 0;
				}
				//不匹配，进
				else
				{
					current_stack.push_back(pushed[flag_a]);
					flag_a++;
					continue;
				}
			}
		}
		if (current_stack.empty() && flag_b >= length)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
};