#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
vector<int> vec;
void dfs(TreeNode* pRoot)
{
	if (!pRoot)  vec.push_back(0x2333);
	else
	{
		vec.push_back(pRoot->val);
		dfs(pRoot->left);
		dfs(pRoot->right);
	}
}

TreeNode* dfs2(int* & p)
{
	if (*p == 0x2333)
	{
		++p;
		return NULL;
	}

	TreeNode* res = new TreeNode(*p);
	++p;
	res->left = dfs2(p);
	res->right = dfs2(p);
	return res;
}
char* Serialize(TreeNode *root) {
	vec.clear();
	dfs(root);
	int* buf = new int[vec.size()];
	for (int i = 0; i < vec.size(); ++i)
		buf[i] = vec[i];
	return (char*)buf;
}
TreeNode* Deserialize(char *str) {
	int* p = (int*)str;
	return dfs2(p);
}
int main62()
{
	return 0;
}