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
//µÝ¹é
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		int leftLength = maxDepth(root->left);
		int rightLength = maxDepth(root->right);
		return (leftLength > rightLength) ? (leftLength + 1) : (rightLength + 1);
	}
};
//µÝ¹é¼òµ¥Ð´·¨
int maxDepth1(TreeNode* root)
{
	return (root == 0) ? 0 : max(maxDepth1(root->left), maxDepth1(root->right)) + 1;
}
//·ÇµÝ¹é
int maxDepth3(TreeNode* root)
{
	if (root == NULL)
		return 0;
	queue<TreeNode*> q;
	q.push(root);
	int level = 0;
	while (!q.empty())
	{
		level++;
		int size = q.size();
		while (size--)
		{
			TreeNode* pNode = q.front();
			q.pop();
			if (pNode->left)
				q.push(pNode->left);
			if (pNode->right)
				q.push(pNode->right);
		}
	}
	return level;
}
int maindp()
{

	return 0;
	
}