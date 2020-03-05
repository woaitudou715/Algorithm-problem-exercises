#include<iostream>
using namespace std;
int Sum_Solution1(int n) {
	int res = n;
	res && (res += Sum_Solution1(n - 1));
	return res;
}
typedef int(*func)(int);
int solution1(int n)
{
	return 0;
}
int Sum_Solution2(int n) {
	static func f[2] = { solution1 ,Sum_Solution2 };
	return n + f[!!n](n - 1);
}
int main()
{
	cout << Sum_Solution2(100) << endl;
	system("pause");
}