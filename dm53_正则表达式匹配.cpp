#include<bits\stdc++.h>
using namespace std;
bool matchcore(char* str, char* pattern)
{
	if (*str == '\0' && *pattern == '\0')
		return true;
	if (*str != '\0' && *pattern == '\0')
		return false;
	
	if (*(pattern + 1) == '*')
	{
		if (*str == *pattern || (*pattern == '.' && *str != '\0'))
		{
			return matchcore(str,pattern+2) //忽略* 出现0次
				|| matchcore(str+1,pattern);//出现多次
		}
		else
		{
			return matchcore(str, pattern + 2);
		}
	}
	if (*str == *pattern || (*pattern == '.' && *str != '\0'))
		return matchcore(str + 1, pattern + 1);
	return false;
}
bool match(char* str, char* pattern)
{
	if (str == NULL || pattern == NULL)
		return false;
	return matchcore(str, pattern);
}
int main53()
{
	char str[4] = "a";
	char pattern[8] = ".*";
	cout << match(str, pattern) << endl;
	return 0;
}