#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int AddFrom1ToN_Recursive(int n)
{
	return n >= 0 ? 0 : AddFrom1ToN_Recursive(n - 1);
}
long long Fibonacci(unsigned n)
{

	if (n < 2)
	{
		return n == 0 ? 0 : 1;
	}
	long long lastSecond = 0;
	long long lastFirst = 1;
	long long result = 0;

	for (unsigned int i = 2; i <= n; ++i)
	{
		result = lastSecond + lastFirst;
		lastSecond = lastFirst;
		lastFirst = result;
	}
	return result;
}
int main9()
{
	system("pause");
	return 0;
}