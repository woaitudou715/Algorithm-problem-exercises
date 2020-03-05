#include<iostream>
#include<vector>
using namespace std;
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};
BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
	int rootValue = startPreorder[0];
	BinaryTreeNode* root = new BinaryTreeNode();
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = NULL;
	if (startPreorder == endPreorder)
	{
		if (startInorder == endInorder && *startPreorder == *endInorder)
			return root;
		else
			return NULL;
	}
	int* rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder != rootValue)
		++rootInorder;
	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;

	if (leftLength > 0)
	{
		root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	if (leftLength < endPreorder - startPreorder)
	{
		root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
	}
	return root;
}
BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
	if (preorder == NULL || inorder == NULL || length <= 0)
		return NULL;
	return  ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}


TreeNode* ConstructCore(vector<int> pre, int startPreorder, int endPreorder,
	vector<int>vin, int startInorder, int endInorder)
{
	if (startPreorder >= endPreorder || startInorder >= endInorder)
		return NULL;
	TreeNode* root = new TreeNode(pre[startPreorder]);
	int pivot;
	for (pivot = startInorder; pivot < endInorder; pivot++)
	{
		if (vin[pivot] == pre[startPreorder])
			break;
	}
	root->left = ConstructCore(pre, startPreorder + 1, startPreorder + pivot - startInorder + 1,
		vin, startInorder, pivot);
	root->right = ConstructCore(pre, startPreorder + pivot - startInorder + 1, endPreorder,
		vin, pivot + 1, endInorder);
	return root;
}
TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
	return ConstructCore(pre, 0, pre.size(), vin, 0, vin.size());
}
int main4()
{
	system("pause");
	return 0;
}