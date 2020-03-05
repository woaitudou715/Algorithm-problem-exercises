#include<iostream>
#include<vector>
using namespace std;
void replaceSpace(char *str, int length)
{
	if (str == NULL || length < 0)
		return;
	int originalLength = 0;
	int numberOfBlank = 0;
	int i = 0;
	while (str[i] != '\0')
	{
		++originalLength;
		if (str[i] == ' ')
			++numberOfBlank;
		++i;
	}
	int newLength = originalLength + numberOfBlank * 2;
	if (newLength > length)
		return;
	int indexOfOriginal = originalLength;
	int indexOfNew = newLength;
	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
	{
		if (str[indexOfOriginal] == ' ')
		{
			str[indexOfNew--] = '0';
			str[indexOfNew--] = '2';
			str[indexOfNew--] = '%';
		}
		else
			str[indexOfNew--] = str[indexOfOriginal];

		--indexOfOriginal;
	}
	char* tem = str;
}
int main2()
{
	char buf[] = "we are happy.";
	replaceSpace(buf, 20);
	
	system("pause");
	return 0;
}