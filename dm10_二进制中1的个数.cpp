#include<iostream>
#include<vector>
#include<stack>
#include<thread>
using namespace std;
int NumOf1(unsigned int n)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (n & flag)
			count++;
		flag = flag << 1;
	}
	return count;
}
int NumberOf1(int n)
{
	int count = 0;
	while (n)
	{
		count++;
		n = n & (n - 1);
	}
	return count;
}
int main10()
{
	cout << NumberOf1(10) << endl;
	system("pause");
	return 0;
}