/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;

	Node() {}

	Node(int _val) {
		val = _val;
		left = NULL;
		right = NULL;
	}

	Node(int _val, Node* _left, Node* _right) {
		val = _val;
		left = _left;
		right = _right;
	}
};
*/
class Solution {
public:
	vector<Node*> node_list;
	Node* treeToDoublyList(Node* root) {
		if (root == NULL) return NULL;
		middle_visit(root);
		for (int i = 0; i < node_list.size(); i++)
		{
			if (i != node_list.size() - 1)
			{
				node_list[i]->right = node_list[i + 1];
			}
			else
			{
				node_list[i]->right = node_list[0];
			}
			if (i != 0)
			{
				node_list[i]->left = node_list[i - 1];
			}
			else
			{
				node_list[i]->left = node_list[node_list.size() - 1];
			}
		}
		return node_list[0];
	}

	void middle_visit(Node* root)
	{
		if (root == NULL) return;
		middle_visit(root->left);
		node_list.push_back(root);
		middle_visit(root->right);
	}
};