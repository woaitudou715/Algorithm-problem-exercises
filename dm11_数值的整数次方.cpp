#include<iostream>
using namespace std;
//边界条件是重点 指数以及底数的值正负  double类型判别等于0 乘法的快速运算 位运算

bool equal(double value1, double value2)
{
	if ((value1 - value2 > -0.0000001) && (value1 - value2 < 0.0000001))
		return true;
	else
		return false;
}
double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;

	double result = PowerWithUnsignedExponent(base, exponent >> 1);
	result = result * result;
	if (exponent & 0x1)
		result = result * base;

	return result;
}
bool g_InvalidInput = false;

double power(double base, int exponent)
{
	g_InvalidInput = false;

	if (equal(base, 0.0) && exponent < 0)
	{
		g_InvalidInput = true;
		return 0.0;
	}

	double result = 1.0;
	unsigned int absExponent = (unsigned int) exponent;

	if (exponent < 0)
		absExponent = (unsigned int)(-exponent);

	for (int i = 1; i <= absExponent; i++)
		result *= base;

	if (exponent < 0)
		result = 1.0 / result;

	return result;

}

int main11()
{
	double base = 5;
	int exponent = 3;
	cout << power(base,exponent) <<endl;
	system("pause");
	return 0;
}