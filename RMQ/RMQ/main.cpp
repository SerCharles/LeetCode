#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
using namespace std;

int the_min[100000][20] = { 0 };
int numbers[100000] = { 0 };
int twice[20] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536 };
int m = 0, n = 0;

class moving_queue
{
public:
	queue<int> main_queue;
	deque<int> main_deque;
	moving_queue()
	{
		while (!main_queue.empty()) main_queue.pop();
		main_deque.clear();
	}
	void push_back(int num)
	{
		main_queue.push(num);
		while (!main_deque.empty() && main_deque.back() > num) main_deque.pop_back();
		main_deque.push_back(num);
	}

	void pop_front()
	{
		if (main_queue.empty() || main_deque.empty()) return;
		if (main_deque.front() == main_queue.front()) main_deque.pop_front();
		main_queue.pop();
	}

	int get_min()
	{
		return main_deque.front();
	}

	void clear()
	{
		while (!main_queue.empty()) main_queue.pop();
		main_deque.clear();
	}
};

void build_list_one(int place, int num)
{
	moving_queue the_queue;
	for (int i = 0; i < num; i++)
	{
		the_queue.push_back(numbers[i]);
	}
	for (int i = 0; i + num <= m; i++)
	{
		int t_min = the_queue.get_min();
		the_min[i][place] = t_min;
		if (i + num < m)
		{
			the_queue.pop_front();
			the_queue.push_back(numbers[i + num]);
		}
	}
	the_queue.clear();
}

void build_list()
{
	int place = 0;
	int num = 1;
	while (num <= m)
	{
		build_list_one(place, num);
		place++;
		num *= 2;
	}
}

int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		cin >> numbers[i];
	}
	build_list();
	vector<int> result_list;
	result_list.clear();
	for (int i = 0; i < n; i++)
	{
		int start, end;
		cin >> start >> end;
		start--;
		end--;
		int length = end - start + 1;
		int current_min = ~(1 << 31);
		for (int i = 16; i >= 0; i--)
		{
			int current_num = 1 << i;
			if ((length >> i) & 1)
			{
				//¿¼ÂÇ½øÀ´
				int my_min = the_min[start][i];
				if (my_min < current_min) current_min = my_min;
				start += current_num;
				length -= current_num;
			}
		}
		result_list.push_back(current_min);
	}
	for (int i = 0; i < result_list.size(); i++)
	{
		cout << result_list[i] << " ";
	}
	return 0;
}
