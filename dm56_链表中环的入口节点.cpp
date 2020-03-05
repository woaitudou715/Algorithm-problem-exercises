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
// ���ҵ����ĳ���  ����ָ��һǰ�Ժ�  ǰ��ָ���߻��ĳ����Ժ����ڵ�����ڴ�����
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
//2 ��һ�����һ������㡣�ֱ���p1��p2ָ������ͷ����p1ÿ����һ����p2ÿ���߶�����
//ֱ��p1==p2�ҵ��ڻ��е����㡣
//�ڶ������һ�����ڡ����ϲ�����p1 == p2ʱ��p2�������ڵ���Ϊ2x, p1�������ڵ���Ϊx, 
//�軷����n���ڵ�, p2��p1����һȦ��2x = n + x; n = x; ���Կ���p1ʵ������һ������
//����������p2ָ������ͷ����p1λ�ò��䣬p1, p2ÿ����һ��ֱ��p1 == p2; ��ʱp1ָ�򻷵����
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