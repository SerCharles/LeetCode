/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<cstdio>
class Solution {
public:
	bool isSubStructure(TreeNode* A, TreeNode* B)
	{
		if (A == NULL || B == NULL)
		{
			return 0;
		}
		if (A->val == B->val)
		{
			bool whether = isThisSub(A, B);
			if (whether)
			{
				return 1;
			}
		}
		bool whether = isSubStructure(A->left, B);
		if (whether)
		{
			return 1;
		}
		whether = isSubStructure(A->right, B);
		return whether;
	}
	bool isThisSub(TreeNode* A, TreeNode* B) {
		if (A == NULL || B == NULL)
		{
			return 0;
		}
		if (A->val != B->val)
		{
			return 0;
		}
		bool whether = 1;
		if (B->left != NULL)
		{
			whether = isThisSub(A->left, B->left);
		}
		if (whether == 0)
		{
			return 0;
		}
		if (B->right != NULL)
		{
			whether = isThisSub(A->right, B->right);
		}
		return whether;
	}
};