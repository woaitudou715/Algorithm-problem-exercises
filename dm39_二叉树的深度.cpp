#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
};
int TreeDepth(TreeNode* pRoot)
{
	if (pRoot == NULL)
		return 0;
	return max(1 + TreeDepth(pRoot->left), 1 + TreeDepth(pRoot->right));
}
int main()
{
	return 0;
}