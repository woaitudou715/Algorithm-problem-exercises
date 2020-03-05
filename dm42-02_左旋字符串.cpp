#include<bits\stdc++.h>
using namespace std;
//第一种解法
string LeftRotateString1(string str, int n) {
	string resstr = str;
	int m = str.size() - n;
	for (int i = 0; i < m; i++)
	{
		resstr[i] = str[i + n];
	}
	for (int i = 0; i < n; i++)
		resstr[m + i] = str[i];
	return resstr;

}
//第二种解法
string LeftRotateString2(string str, int n) {
	if (n < 0) return NULL;
	if (n == 0) return str;
	string strTemp = "";

	strTemp = str.substr(0, n);
	str.erase(0, n);
	str += strTemp;
	return str;

}
//第三种解法
string LeftRotateString3(string str, int n) {
	int len = str.length();
	if (len == 0) return "";
	n = n % len;
	str += str;
	return str.substr(n, len);
}
int main4202()
{
	string str = "abcdefg";
	cout << LeftRotateString3(str, 2);
	return 0;
}