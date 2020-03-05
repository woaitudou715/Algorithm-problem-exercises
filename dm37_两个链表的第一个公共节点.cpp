#include<bits/stdc++.h>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
//��һ�ַ������� ջ��������������Ľڵ㣬ջ��һ��ʱ���������һ����ͬ�Ľڵ㼴Ϊ����
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
//�ڶ��� ������ͬ�й�����㣬��һ�ξͱ�������û�й�����㣬�ߵ�β��NULL����������NULL
//���Ȳ�ͬ�й�����㣬��һ���ֵ�ͳ����ˣ��ڶ���һ�𵽹�����㣻û�й�����һ�𵽽�βNULL��
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
	//��һ��List
	a->next = b;
	b->next = c;
	c->next = f;
	f->next = g;
	//�ڶ���List
	d->next = e;
	e->next = f;
	f->next = g;
	FindFirstCommonNode(a, d);
	return 0;
}