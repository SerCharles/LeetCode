#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

struct Node
{
	int id;
	int val;
	Node(int i, int v)
	{
		val = v;
		id = i;
	}


};

struct cmp
{
	//小优先
	bool operator () (Node& a, Node& b)
	{
		if (a.val != b.val) return a.val > b.val;
		else return a.id > b.id;
	}
};

//小优先
bool compare (Node& a, Node& b)
{
	if (a.val != b.val) return a.val < b.val;
	else return a.id < b.id;
}

int main()
{
	vector<Node> list;
	priority_queue<Node,vector<Node>, cmp> my_queue;
	set<int> my_set;
	my_set.clear();
	list.clear();
	while (!my_queue.empty()) my_queue.pop();
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int nova;
		cin >> nova;
		Node nova_node(i, nova);
		list.push_back(nova_node);
		my_queue.push(nova_node);
		if (my_set.find(nova) == my_set.end())
		{	
			cout << nova << endl;
			my_set.insert(nova);
		}
	}
	sort(list.begin(), list.end(), compare);


	for (int i = 0; i < list.size(); i++)
	{
		cout << list[i].val << " " <<list[i].id<<endl;
	}

	
	while (!my_queue.empty()) {
		Node front = my_queue.top();
		cout << front.val << " " << front.id << endl;
		my_queue.pop();
	}
	return 0;
}