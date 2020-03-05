#include<iostream>
#include<map>
#include<vector>
#include<string>

using namespace std;
vector<string> vec;
void PrintStrOrder(string& str,int n)
{
	if (str.empty())
		return;
	
	if (n == str.size())
	{
		
		vec.push_back(str);
	}
	else
	{
		for (int i = n; i < str.size(); i++)
		{
			char tmp = str[i];
			str[i] = str[n];
			str[n] = tmp;

			PrintStrOrder(str, n+1);

			tmp = str[i];
			str[i] = str[n];
			str[n] = tmp;
		}
	}
}
int main28()
{
	string str = "abc";
	PrintStrOrder(str,0);
	for (auto it : vec)
		cout << it << endl;
	system("pause");
	return 0;
}