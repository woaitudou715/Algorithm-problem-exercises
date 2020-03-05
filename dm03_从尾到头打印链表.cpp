#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};
void AddToTail(ListNode** pHead, int value)
{
	ListNode* pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = NULL;
	if (*pHead == NULL)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != NULL)
			pNode = pNode->m_pNext;
		pNode->m_pNext = pNew;
	}
	
}
void RemoveNode(ListNode** pHead, int value)
{
	if (pHead == NULL || *pHead == NULL)
		return;
	ListNode* pToBeDeleteNode = NULL;
	if ((*pHead)->m_nValue == value)
	{
		pToBeDeleteNode = *pHead;
		*pHead = (*pHead)->m_pNext;
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->m_pNext != NULL && pNode->m_pNext->m_nValue != value)
		{
			pNode = pNode->m_pNext;
		}
		if (pNode->m_pNext != NULL && pNode->m_pNext->m_nValue == value)
		{
			pToBeDeleteNode = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}
	if (pToBeDeleteNode != NULL)
	{
		delete pToBeDeleteNode;
		pToBeDeleteNode = NULL;
	}
}
void PrintListFromTailToHead(ListNode* pHead)
{
	if (pHead == NULL)
		return;
	stack<ListNode*> node;
	ListNode* pNode = pHead;
	while (pNode != NULL)
	{
		node.push(pNode);
		pNode = pNode->m_pNext;
	}
	while (!node.empty())
	{
		pNode = node.top();
		node.pop();
		cout << pNode->m_nValue << endl;
	}
}
//µÝ¹é´òÓ¡
void PrintListReversingly_Recursively(ListNode* pHead)
{
	if (pHead != NULL)
	{
		if (pHead->m_pNext != NULL)
		{
			PrintListFromTailToHead(pHead->m_pNext);
		}
		cout << pHead->m_nValue << endl;
	}
}
int main()
{
	

	system("pause");
	return 0;
}