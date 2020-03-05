#include<iostream>
#include<vector>
#include<stack>
using namespace std;
template <typename T> class CQueue
{
public:
	CQueue()
	{

	}
	~CQueue()
	{

	}
	void appendTail(const T& node)
	{
		if (stack2.empty())
		{
			stack1.push(node);
			T stackHead;
			while (!stack1.empty())
			{
				stackHead = stack1.top();
				stack2.push(stackHead);
				stack1.pop();
			}
		}
		else
			stack1.push(node);
	}
	T deleteHead()
	{
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				T& stackHead = stack1.top();
				stack2.push(stackHead);
				stack1.pop();
			}
		}
		
		T head = stack2.top();
		stack2.pop();

		return head;
	}
private:
	stack<T> stack1; 
	stack<T> stack2;
};
int main05()
{
	system("pause");
	return 0;
}