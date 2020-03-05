#include<bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
//第一种方法利用 栈来保存两个链表的节点，栈顶一致时弹出，最后一个相同的节点即为所求
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
	if (pHead1 == NULL && pHead2 == NULL)
		return NULL;
	ListNode* pNode1 = pHead1;
	ListNode* pNode2 = pHead2;
	ListNode* pResult(0);
	stack<ListNode*> sta1;
	stack<ListNode*> sta2;
	while (pNode1)
	{
		sta1.push(pNode1);
		pNode1 = pNode1->next;
	}
	while (pNode2)
	{
		sta2.push(pNode2);
		pNode2 = pNode2->next;
	}
	while (!sta1.empty() && !sta2.empty())
	{
		if (sta1.top() == sta2.top())
		{
			pResult = sta1.top();
			sta1.pop();
			sta2.pop();
		}
		else
			break;
	}
	return pResult;
}
//第二种 长度相同有公共结点，第一次就遍历到；没有公共结点，走到尾部NULL相遇，返回NULL
//长度不同有公共结点，第一遍差值就出来了，第二遍一起到公共结点；没有公共，一起到结尾NULL。
ListNode* FindFirstCommonNode1(ListNode *pHead1, ListNode *pHead2) {
	ListNode *p1 = pHead1;
	ListNode *p2 = pHead2;
	while (p1 != p2) {
		p1 = (p1 == NULL ? pHead2 : p1->next);
		p2 = (p2 == NULL ? pHead1 : p2->next);
	}
	return p1;
}
int main()
{
	ListNode* a = new ListNode(1);
	ListNode* b = new ListNode(2);
	ListNode* c = new ListNode(3);
	ListNode* d = new ListNode(4);
	ListNode* e = new ListNode(5);
	ListNode* f = new ListNode(6);
	ListNode* g = new ListNode(7);
	//第一个List
	a->next = b;
	b->next = c;
	c->next = f;
	f->next = g;
	//第二个List
	d->next = e;
	e->next = f;
	f->next = g;
	FindFirstCommonNode(a, d);
	return 0;
}