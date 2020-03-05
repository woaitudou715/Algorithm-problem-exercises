#include<bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
ListNode* deleteDuplication(ListNode* pHead)
{
	ListNode* pNewHead;
	return pNewHead;
}
int main()
{
	ListNode* pNode = new ListNode(1);
	pNode->next = new ListNode(2);
	pNode->next->next = new ListNode(3);
	pNode->next->next->next = new ListNode(3);
	pNode->next->next->next->next = new ListNode(4);
	pNode->next->next->next->next->next = new ListNode(4);
	pNode->next->next->next->next->next->next = new ListNode(5);
	pNode->next->next->next->next->next->next->next = NULL;
	deleteDuplication(pNode);
	return 0;
}