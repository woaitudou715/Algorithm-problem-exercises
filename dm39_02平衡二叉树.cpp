#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
};
bool IsBalanced(TreeNode* pRoot, int* depth)
{
	if (pRoot == NULL)
	{
		*depth = 0;
		return true;
	}

	int left;

	int right;
	if (IsBalanced(pRoot->left, &left) && IsBalanced(pRoot->right, &right))
	{
		int diff = left - right;
		if (diff > -1 || diff < 1)
		{
			*depth = 1 + (left > right ? left : right);
			return true;
		}
	}

	return false;
}
bool IsBalanced_Solution(TreeNode* pRoot) {
	int depth = 0;
	return IsBalanced(pRoot, &depth);
}

//�������� ��������ʱ��������һ���ڵ㣬�����������Ѿ�����  �����Ե������жϣ�ÿ���ڵ�ֻ��Ҫ����һ��
bool isBalanced = true;
int getDepth(TreeNode* root) {
	if (root == NULL)
		return 0;
	int left = getDepth(root->left);
	int right = getDepth(root->right);

	if (abs(left - right) > 1) {
		isBalanced = false;
	}
	return right > left ? right + 1 : left + 1;

}
bool IsBalanced_Solution(TreeNode* pRoot)
{
	getDepth(pRoot);
	return isBalanced;
}
int main()
{
	return 0;
}