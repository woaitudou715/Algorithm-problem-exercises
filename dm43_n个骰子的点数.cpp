#include<bits/stdc++.h>
using namespace std;
int maxvalue = 6;
void PrintProability(int n)
{
	if (n < 1)
		return;
	vector<vector<int>> prob(2, vector<int>(n * maxvalue + 1, 0));
	int flag = 0;
	for (int i = 1; i <= maxvalue; ++i)
		prob[flag][i] = 1;
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 0; j < i; ++j)
			prob[1 - flag][j] = 0;
		for (int k = i; k <= i * maxvalue; ++k)
		{
			prob[1 - flag][k] = 0;
			for (int j = 1; j <= k && j <= maxvalue; ++j)
				prob[1 - flag][k] += prob[flag][k - j];
		}
		flag = 1 - flag;
	}
	double total = pow((double)maxvalue, n);
	for (int i = n; i <= maxvalue * n; ++i)
	{
		double ratio = (double)prob[flag][i] / total;
		cout << i << ':' << ratio << endl;
	}
}
int main()
{
	int n = 2;
	PrintProability(2);
	return 0;
}