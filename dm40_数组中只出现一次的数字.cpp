#include<bits\stdc++.h>
#include<limits>
using namespace std;
int FindFirstBits1(int num)
{
	int indexBit = 0;
	while (((num & 1) == 0) && (indexBit < 8 * sizeof(int)))
	{
		++indexBit;
		num = num >> 1;
	}
	return indexBit;
}
bool IsBit1(int num, int indexBit)
{
	num = num >> indexBit;
	return (num & 1);
}
void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
	if (data.empty())
		return;
	int resultExclusiveOR = 0;
	for (auto it : data)
		resultExclusiveOR ^= it;
	int indexof1 = FindFirstBits1(resultExclusiveOR);

	*num1 = *num2 = 0;
	for (auto it : data)
	{
		if (IsBit1(it, indexof1))
			*num1 ^= it;
		else
			*num2 ^= it;
	}
}
int main()
{
	vector<int> data;
	data.push_back(2);
	data.push_back(4);
	data.push_back(3);
	data.push_back(6);
	data.push_back(3);
	data.push_back(2);
	data.push_back(5);
	data.push_back(5);
	int num1 = 0;
	int num2 = 0;

	FindNumsAppearOnce(data, &num1, &num2);
	//cout << num1 <<" "<< num2 << endl;
	cout << numeric_limits<float>::min() << endl;
	return 0;
}