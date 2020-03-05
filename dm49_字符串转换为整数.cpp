#include<iostream>
#include<vector>
#include<string>
#include<limits>
using namespace std;

enum status { kValid = 0, kInvalid };
int g_status = kValid;

int StrToInt(string str)
{
	g_status = kInvalid;
	int num = 0;
	int index = 0;
	bool minus = false;
	if (!str.empty() && str[index] != '\0')
	{
		if (str[index] == '+')
			index++;
		else if (str[index] == '-')
		{
			index++;
			minus = true;
		}
		
	}
	if (str[index] != '\0')
	{
		while (str[index] != '\0')
		{
			if (str[index] >= '0' && str[index] <= '9')
			{
				int flag = minus ? -1 : 1;
				num = num * 10 + flag * (str[index] - '0');

				if ((!minus && num > INT_MAX) || (minus && num < INT_MIN))
				{
					num = 0;
					break;
				}
				index++;
			}
			else
			{
				num = 0;
				break;
			}
		}
		if (str[index] == '\0')
			g_status = kValid;
	}
		
	return num;
}
int main49()
{
	string str = "-12345655555555555";
	cout << StrToInt(str) << endl;
	system("pause");
	return 0;
}