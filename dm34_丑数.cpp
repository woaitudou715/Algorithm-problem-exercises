#include<iostream>
using namespace std;
//1.��Ҫ��ÿһ����������ʱ�临�Ӷȸ�
bool IsUglyNum(int num)
{
	while (num % 2 == 0)
		num /= 2;
	while (num % 3 == 0)
		num /= 3;
	while (num % 5 == 0)
		num /= 5;
	return (num == 1) ? true : false;
}
int GetUglyNumber_Solution(int index) {
	int count = 0;
	int result = 0;
	while (count < index)
	{
		result++;
		if (IsUglyNum(result))
			count++;
	}
	return result;
}
//2.��ÿһ����������������ʱ�任ȡ�ռ�
int MinNum(int num1, int num2, int num3)
{
	int num = (num1 > num2) ? num2 : num1;
	return num > num3 ? num3 : num;
}
int GetUglyNum(int index)
{
	if (index < 1)
		return 0;
	int* uglyNum = new int[index];
	uglyNum[0] = 1;
	int uglyCount = 1;
	int* pNextNum2 = uglyNum;
	int* pNextNum3 = uglyNum;
	int* pNextNum5 = uglyNum;
	while (uglyCount < index)
	{
		uglyNum[uglyCount] = MinNum(*pNextNum2 * 2, *pNextNum3 * 3, *pNextNum5 * 5);
		while (*pNextNum2 * 2 <= uglyNum[uglyCount])
			pNextNum2++;
		while (*pNextNum3 * 3 <= uglyNum[uglyCount])
			pNextNum3++;
		while (*pNextNum5 * 5 <= uglyNum[uglyCount])
			pNextNum5++;
		++uglyCount;
	}
	int result =  uglyNum[uglyCount - 1];
	delete[] uglyNum;
	return result;
}
int main34()
{
	cout << GetUglyNum(5) << endl;
	system("pause");
	return 0;
}
