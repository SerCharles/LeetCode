#include<iostream>
#include<vector>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	//以下三个都是按照先序遍历
	vector<TreeNode*> node_list;
	vector<int> father_list;
	vector<int> sum_list;
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> result;
		get_total_sum(root, -1, 0);
		for (int i = 0; i < sum_list.size(); i++)
		{
			if (node_list[i]->left == NULL && node_list[i]->right == NULL && sum_list[i] == sum)
			{
				vector<int> list = get_route(i);
				result.push_back(list);
			}
		}
		return result;
	}

	void get_total_sum(TreeNode* root, int father_num, int current_sum)
	{
		if (root == NULL) return;
		node_list.push_back(root);
		father_list.push_back(father_num);
		int new_sum = current_sum + root->val;
		sum_list.push_back(new_sum);
		int current = node_list.size() - 1;
		get_total_sum(root->left, current, new_sum);
		get_total_sum(root->right, current, new_sum);
	}

	vector<int> get_route(int leaf_place)
	{
		vector<int> old_list;
		vector<int> new_list;
		int current = leaf_place;
		while (current != -1)
		{
			old_list.push_back(node_list[current]->val);
			current = father_list[current];
		}
		for (int i = old_list.size() - 1; i >= 0; i--)
		{
			new_list.push_back(old_list[i]);
		}
		return new_list;
	}
};