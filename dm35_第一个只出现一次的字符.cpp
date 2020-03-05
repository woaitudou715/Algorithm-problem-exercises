#include<iostream>
#include<string>
using namespace std;
int FirstNotRepeatingChar(string str) {
	char hashTablle[256];
	for (int i = 0; i < 256; i++)
		hashTablle[i] = 0;
	for (int i = 0; i < str.size(); i++)
	{
		hashTablle[str[i]]++;
	}
	for (int i = 0; i < str.size(); i++)
	{
		if (hashTablle[str[i]] == 1)
			return i;
	}
	return -1;

}
int main35()
{
	//string str = "abaccdeff";
	//cout << FirstNotRepeatingChar(str) << endl;
	int n;
	while (cin >> n)
	{
		if ((n & (n - 1)) == 0)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	system("pause");
	return 0;
}