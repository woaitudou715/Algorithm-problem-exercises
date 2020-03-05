#include<bits\stdc++.h>
using namespace std;
void ScanDigits(char** str)
{
	while (**str != '\0' && **str >= '0' && **str <= '9')
		++(*str);
}
bool isExponential(char** str)
{
	if (**str != 'e' && **str != 'E')
		return false;
	++(*str);
	if (**str == '-' || **str == '+')
		++(*str);
	if (**str == '\0')
		return false;
	ScanDigits(str);
	return (**str == '\0') ? true : false;
}
bool isNumeric(char* string)
{
	if (string == NULL)
		return false;
	if (*string == '-' || *string == '+')
		++string;
	if (*string == '\0')
		return false;
	bool numeric = true;
	ScanDigits(&string);
	if (*string != '\0')
	{
		if (*string == '.')
		{
			++string;
			ScanDigits(&string);
			if (*string == 'e' || *string == 'E')
				numeric = isExponential(&string);
		}
		else if (*string == 'e' || *string == 'E')
		{
			numeric = isExponential(&string);
		}
		else
			numeric = false;
	}
	return numeric && *string == '\0';
}
int main()
{
	char str[] = "12e+5";
	cout << isNumeric(str) << endl;
	return 0;
}
//12e+5.4