#include<iostream>
#include<map>
#include<vector>
using namespace std;
struct ComplexListNode {
	int m_nValue;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pSibling;
	ComplexListNode(int x) :
		m_nValue(x), m_pNext(NULL), m_pSibling(NULL) {
	}

};

//分三步进行 先将clone节点放在每一个节点后面 寻找随机节点的指向 拆分开两部分
void CloneNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	while (pNode != NULL)
	{
		ComplexListNode* pCloned = new ComplexListNode(0);
		pCloned->m_nValue = pNode->m_nValue;
		pCloned->m_pNext = pNode->m_pNext;
		pCloned->m_pSibling = NULL;

		pNode->m_pNext = pCloned;
		pNode = pCloned->m_pNext;
	}
}
void CloneSiblingNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	while (pNode)
	{
		ComplexListNode* pCloned = pNode->m_pNext;
		if (pNode->m_pSibling != NULL)
		{
			pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
		}
		pNode = pCloned->m_pNext;
	}
}
ComplexListNode* ReconnectNodes(ComplexListNode* pHead)
{
	ComplexListNode* pClonedHead = NULL;
	ComplexListNode* pClonedNode = NULL;
	ComplexListNode* pNode = pHead;
	if (pNode->m_pNext != NULL)
	{
		pClonedHead = pClonedNode = pNode->m_pNext;
		pNode->m_pNext = pClonedNode->m_pNext;
		pNode = pNode->m_pNext;
	}
	while (pNode)
	{
		pClonedNode->m_pNext = pNode->m_pNext;
		pClonedNode = pClonedNode->m_pNext;
		pNode->m_pNext = pClonedNode->m_pNext;
		pNode = pNode->m_pNext;
	}
	return pClonedHead;
}
ComplexListNode* clone(ComplexListNode* pHead)
{
	CloneNodes(pHead);
	CloneSiblingNodes(pHead);
	return ReconnectNodes(pHead);
}


//用哈希表通过空间换取时间
typedef map<ComplexListNode*, ComplexListNode*> MAP;
ComplexListNode* clonenode(ComplexListNode* pHead, MAP &hashnode)  //复制一个链表
{
	ComplexListNode *pClonedHead = new ComplexListNode(0); //建立一个头结点
	ComplexListNode *pNode = pClonedHead, *tmp;
	while (pHead)
	{
		tmp = new ComplexListNode(pHead->m_nValue);
		pNode->m_pNext = tmp;
		hashnode[pHead] = tmp;

		pNode = pNode->m_pNext;
		pHead = pHead->m_pNext;
	}
	return pClonedHead->m_pNext;
}
void linkRandomNode(ComplexListNode* pHead, ComplexListNode* pClonedHead, MAP &hashnode)
{
	while (pClonedHead)
	{
		pClonedHead->m_pSibling = hashnode[pHead->m_pSibling];   //将对应节点映射过来

		pClonedHead = pClonedHead->m_pNext;
		pHead = pHead->m_pNext;
	}
}
ComplexListNode* Clone(ComplexListNode* pHead)
{
	if (pHead == nullptr) 
		return nullptr;
	MAP hashnode;
	ComplexListNode* pClonedHead = clonenode(pHead, hashnode);
	linkRandomNode(pHead, pClonedHead, hashnode);
	return pClonedHead;
}

int main26()
{
	return 0;
	system("pause");

}