/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};
*/
class Solution {
public:
	vector<Node*> node_vector;
	vector<Node*> new_node_vector;
	vector<Node*> random_vector;
	int get_place(Node* place)
	{
		int num = 0;
		while (place != NULL)
		{
			place = place->next;
			num++;
		}
		return node_vector.size() - num;
	}

	Node* copyRandomList(Node* head) {
		//¹¹½¨Ë³ÐòÁ´±í
		if (head == NULL)
		{
			return NULL;
		}
		current = head;
		while (current != NULL)
		{
			Node* new_node = new Node(current.val);
			new_node_vector.push_back(new_node);
			node_vector.push_back(current);
			current = current->next;
		}

		current = head;
		while (current != NULL)
		{
			if (current->random == NULL)
			{
				random_vector.push_back(NULL);
			}
			else
			{
				int place = get_place(current->random);
				random_vector.push_back(new_node_vector[place]);
			}
			current = current->next;
		}

		
		for (int i = 0; i < new_node_vector.size(); i++)
		{
			if (i != new_node_vector.size() - 1)
			{
				new_node_vector[i]->next = new_node_vector[i + 1];
			}
			else
			{
				new_node_vector[i]->next = NULL;
			}
			new_node_vector[i]->random = random_vector[i];
		}
		return new_node_vector[0];
	}

};