#include<iostream>
#include<list>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
// 先找到环的长度  两个指针一前以后  前面指针走环的长度以后两节点在入口处相遇
class Solution {
public:
	ListNode* GetSectionNode(ListNode* pNode)
	{
		ListNode* pBehind = pNode;
		if (pBehind == NULL)
			return NULL;
		ListNode* pAhead = pBehind->next;

		while (pAhead != NULL && pBehind != NULL)
		{
			if (pBehind == pAhead)
				return pBehind;
			pBehind = pBehind->next;

			pAhead = pAhead->next;
			if (pAhead != NULL)
				pAhead = pAhead->next;
		}
		return NULL;
	}
	int GetLoopLength(ListNode* pNode)
	{
		int len = 1;
		ListNode* pTmp = pNode;
		while (pTmp->next != pNode)
		{
			len++;
			pTmp = pTmp->next;
		}
		return len;
	}
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if (pHead == NULL)
			return NULL;
		ListNode* pAhead = pHead;
		ListNode* pBehind = pHead;
		ListNode* pInterSec = GetSectionNode(pHead);
		if (pInterSec == NULL)
			return NULL;
		int len = GetLoopLength(pInterSec);
		while(len--)
		{
		    pAhead = pAhead->next;
		}
		while (pAhead != pBehind)
		{
			pAhead = pAhead->next;
			pBehind = pBehind->next;
		}
		return pBehind;
	}
};
//2 第一步，找环中相汇点。分别用p1，p2指向链表头部，p1每次走一步，p2每次走二步，
//直到p1==p2找到在环中的相汇点。
//第二步，找环的入口。接上步，当p1 == p2时，p2所经过节点数为2x, p1所经过节点数为x, 
//设环中有n个节点, p2比p1多走一圈有2x = n + x; n = x; 可以看出p1实际走了一个环的
//步数，再让p2指向链表头部，p1位置不变，p1, p2每次走一步直到p1 == p2; 此时p1指向环的入口
ListNode* EntryNodeOfLoop(ListNode* pHead)
{
	if (pHead == NULL || pHead->next == NULL)
		return NULL;

	ListNode* pSlow = pHead;
	ListNode* pFast = pHead;

	while (pFast != NULL && pFast->next != NULL)
	{
		pSlow = pSlow->next;
		pFast = pFast->next->next;

		if (pSlow == pFast)
		{
			pFast = pHead;
			while (pFast != pSlow)
			{
				pFast = pFast->next;
				pSlow = pSlow->next;
			}
			if (pFast == pSlow)
				return pFast;
		}
	}
	return NULL;
}

int main()
{
	return 0;
}