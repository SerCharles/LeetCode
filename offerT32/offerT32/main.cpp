#include<iostream>
#include<vector>
using namespace std;


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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;
		vector<TreeNode*> queue;
		int flag_start = 0;
		int flag_end = 0;
		int current_step = 1;
		queue.push_back(root);
		if (root == NULL) return result;
		while (flag_start <= flag_end)
		{
			//正序打印，反序生成
			vector<int> current;
			for (int i = flag_start; i <= flag_end; i++)
			{
				current.push_back(queue[i]->val);
			}
			result.push_back(current);
			int new_num = 0;
			for (int i = flag_end; i >= flag_start; i--)
			{
				//先左后右
				if (current_step % 2 == 0)
				{
					if (queue[i]->left != NULL)
					{
						new_num++;
						queue.push_back(queue[i]->left);
					}
					if (queue[i]->right != NULL)
					{
						new_num++;
						queue.push_back(queue[i]->right);
					}
				}
				//先右后左
				else
				{
					if (queue[i]->right != NULL)
					{
						new_num++;
						queue.push_back(queue[i]->right);
					}
					if (queue[i]->left != NULL)
					{
						new_num++;
						queue.push_back(queue[i]->left);
					}
				}
			}
			//更新队列
			flag_start = flag_end + 1;
			flag_end += new_num;
			current_step++;
		}
		return result;
	}
};