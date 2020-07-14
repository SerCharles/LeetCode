#include<iostream>
#include<vector>
using namespace std;

/*
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
*/

class Solution {
public:
	//preorder,inorder是整个数组，rootplace是根节点位置，后面两个代表当前要建立的子树位置，递归算法
	TreeNode* buildTreeRecur(vector<int>& preorder, vector<int>& inorder, 
		int rootPlace, int inOrderStart, int inOrderEnd) 
	{
		int pivot = preorder[rootPlace];
		int thePlace = -1;
		//叶子结点
		if (inOrderStart == inOrderEnd) 
		{
			TreeNode* new_node = new TreeNode(pivot);
			return new_node;
		}
		for (int i = inOrderStart; i <= inOrderEnd; i++) 
		{
			if (inorder[i] == pivot)
			{
				thePlace = i;
				break;
			}
		}

		//只有右子树
		if (thePlace == inOrderStart) 
		{
			TreeNode* new_node = new TreeNode(pivot);
			new_node->right = buildTreeRecur(preorder, inorder, rootPlace + 1, inOrderStart + 1, inOrderEnd);
			return new_node;
		}
		//只有左子树
		else if (thePlace == inOrderEnd) 
		{
			TreeNode* new_node = new TreeNode(pivot);
			new_node->left = buildTreeRecur(preorder, inorder, rootPlace + 1, inOrderStart, inOrderEnd - 1);
			return new_node;
		}
		//都有 
		else
		{
			TreeNode* new_node = new TreeNode(pivot);
			new_node->left = buildTreeRecur(preorder, inorder, rootPlace + 1, inOrderStart, thePlace - 1);
			int left_size = thePlace - inOrderStart;
			new_node->right = buildTreeRecur(preorder, inorder, rootPlace + left_size + 1, thePlace + 1, inOrderEnd);
			return new_node;
		}

	}


	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
	{
		if (preorder.size() == 0)
		{
			return NULL;
		}
		return buildTreeRecur(preorder, inorder, 0, 0, inorder.size() - 1);
	}
};

