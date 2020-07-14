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
	//preorder,inorder���������飬rootplace�Ǹ��ڵ�λ�ã�������������ǰҪ����������λ�ã��ݹ��㷨
	TreeNode* buildTreeRecur(vector<int>& preorder, vector<int>& inorder, 
		int rootPlace, int inOrderStart, int inOrderEnd) 
	{
		int pivot = preorder[rootPlace];
		int thePlace = -1;
		//Ҷ�ӽ��
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

		//ֻ��������
		if (thePlace == inOrderStart) 
		{
			TreeNode* new_node = new TreeNode(pivot);
			new_node->right = buildTreeRecur(preorder, inorder, rootPlace + 1, inOrderStart + 1, inOrderEnd);
			return new_node;
		}
		//ֻ��������
		else if (thePlace == inOrderEnd) 
		{
			TreeNode* new_node = new TreeNode(pivot);
			new_node->left = buildTreeRecur(preorder, inorder, rootPlace + 1, inOrderStart, inOrderEnd - 1);
			return new_node;
		}
		//���� 
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

