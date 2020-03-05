#include<iostream>
#include<vector>
using namespace std;
//1 遍历每一个数求对应的数是否包含1 相加
int Numberof1(int n)
{
	int number = 0;
	while (n)
	{
		if (n % 10 == 1)
			number++;
		n /= 10;
	}
	return number;
}
int NumberOf1Between1AndN_Solution(int n)
{
	int number = 0;
	for (int i = 1; i <= n; i++)
		number += Numberof1(i);
	return number;
}
//2 按数字规律来
int main32()
{
	cout << NumberOf1Between1AndN_Solution(12) << endl;
	system("pause");
	return 0;
}