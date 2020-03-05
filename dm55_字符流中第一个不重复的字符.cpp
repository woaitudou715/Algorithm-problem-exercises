#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
	//Insert one char from stringstream
	
	void Insert(char ch)
	{
		s += ch;
		hash[ch]++;
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		int n = s.size();
		for (int i = 0; i < n; i++)
		{
			if (hash[s[i]] == 1)
				return s[i];
		}
		return '#';
	}
private:
	char hash[256] = {0};
	string s;
};
int main()
{
	system("pause");
	return 0;
}