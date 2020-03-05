#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void Mirror(TreeNode *pRoot) {
	if (pRoot == NULL)
		return;
	if (pRoot->left == NULL && pRoot->right == NULL)
		return;
	TreeNode* pTmp = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = pTmp;
	if (pRoot->left)
		Mirror(pRoot->left);
	if (pRoot->right)
		Mirror(pRoot->right);
}
int mainmir()
{
	return 0;
}