#include<iostream>
#include<map>
#include<vector>
using namespace std;
struct BinaryTreeNode{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode(int x) : m_nValue(x), m_pLeft(NULL), m_pRight(NULL) {}
	BinaryTreeNode() { m_pLeft = m_pRight = NULL; }
};
void insertNode(BinaryTreeNode *node, int value) {

	if (value <= node->m_nValue) {
		if (!node->m_pLeft) {
			node->m_pLeft = new BinaryTreeNode(value);
		}
		else {
			insertNode(node->m_pLeft, value);
		}
	}
	else {
		if (!node->m_pRight) {
			node->m_pRight = new BinaryTreeNode(value);
		}
		else {
			insertNode(node->m_pRight, value);
		}
	}
}
void ConVert(BinaryTreeNode* pRoot, BinaryTreeNode** pLastNodeInList)
{
	if (pRoot == NULL)
		return;
	BinaryTreeNode* pCurrent = pRoot;
	if (pCurrent->m_pLeft != NULL)
		ConVert(pCurrent->m_pLeft, pLastNodeInList);

	pCurrent->m_pLeft = *pLastNodeInList;
	if (*pLastNodeInList != NULL)
		(*pLastNodeInList)->m_pRight = pCurrent;
	*pLastNodeInList = pCurrent;

	if (pCurrent->m_pRight != NULL)
		ConVert(pCurrent->m_pRight, pLastNodeInList);
}
//中序遍历  保存当前节点，当前节点的左节点为最新节点  最新节点的右节点为当前节点  更新最新节点为当前节点
BinaryTreeNode* bstToDeList(BinaryTreeNode* pHead)
{
	if (pHead == NULL)
		return NULL;
	BinaryTreeNode* pLastNodeInList = NULL;
	ConVert(pHead, &pLastNodeInList);
	BinaryTreeNode* pHeadOfList = pLastNodeInList;
	while (pHeadOfList != NULL && pHeadOfList->m_pLeft != NULL)
	{
		pHeadOfList = pHeadOfList->m_pLeft;
	}
	return pHeadOfList;
}
int main27()
{
	BinaryTreeNode pNode(62);
	insertNode(&pNode, 73);
	insertNode(&pNode, 22);
	insertNode(&pNode, 93);
	insertNode(&pNode, 43);
	insertNode(&pNode, 55);
	insertNode(&pNode, 14);
	insertNode(&pNode, 28);
	insertNode(&pNode, 65);
	insertNode(&pNode, 39);
	insertNode(&pNode, 81);
	BinaryTreeNode* pResult = bstToDeList(&pNode);

	system("pause");
	return 0;
}