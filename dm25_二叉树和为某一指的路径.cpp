#include<iostream>
#include<vector>
using namespace std;
struct BinaryTreeNode {
	int nValue;
	BinaryTreeNode* pLeft;
	BinaryTreeNode* pRight;
};
void PrintPathCore(BinaryTreeNode* pRoot,int exceptedSum,int currentSum,vector<int> path)
{
	currentSum += pRoot->nValue;
	path.push_back(pRoot->nValue);
	bool isLeaf = (pRoot->pLeft == NULL) && (pRoot->pRight == NULL);
	if (currentSum == exceptedSum && isLeaf)
	{
		for (auto it : path)
			cout << it << " ";
		cout << endl;
	}
	if (pRoot->pLeft)
		PrintPathCore(pRoot->pLeft, exceptedSum, currentSum, path);
	if (pRoot->pRight)
		PrintPathCore(pRoot->pRight, exceptedSum, currentSum, path);
	path.pop_back();
}
void PrintPathWithN(BinaryTreeNode* pRoot,int val)
{
	if (pRoot == NULL)
		return;
	int currentSum = 0;
	int exceptedSum = val;
	vector<int> path;
	PrintPathCore(pRoot, exceptedSum, currentSum, path);
}
int main25()
{
	BinaryTreeNode* pRoot = new BinaryTreeNode();
	pRoot->nValue = 10;
	pRoot->pLeft = new BinaryTreeNode();
	pRoot->pLeft->nValue = 5;
	pRoot->pRight = new BinaryTreeNode();
	pRoot->pRight->pLeft = NULL;
	pRoot->pRight->pRight = NULL;
	pRoot->pRight->nValue = 12;

	pRoot->pLeft->pLeft = new BinaryTreeNode();
	pRoot->pLeft->pLeft->nValue = 4;
	pRoot->pLeft->pLeft->pLeft = NULL;
	pRoot->pLeft->pLeft->pRight = NULL;
	pRoot->pLeft->pRight = new BinaryTreeNode();
	pRoot->pLeft->pRight->nValue = 7;
	pRoot->pLeft->pRight->pLeft = NULL;
	pRoot->pLeft->pRight->pRight = NULL;
	PrintPathWithN(pRoot,22);
	int str[] = { 5,7,6,9,11,10,8 };
	system("pause");
	return 0;
}