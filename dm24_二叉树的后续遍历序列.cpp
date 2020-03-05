#include<iostream>
using namespace std;
bool vertifySequenceOfBST(int sequence[],int length)
{
	if (length < 0)
		return false;
	bool possible = false;
	int root = sequence[length - 1];

	int nBegin = 0;
	for (; nBegin < length - 1; nBegin++)
	{
		if (sequence[nBegin] > root)
			break;
	}

	int nEnd = nBegin;
	for (; nEnd < length-1; nEnd++)
	{
		if (sequence[nEnd] < root)
			return false;
	}
	bool left = true;
	if (nBegin > 0)
		left = vertifySequenceOfBST(sequence, nBegin);
	bool right = true;
	if (length - nBegin - 1 > 0)
		right = vertifySequenceOfBST(sequence + nBegin, length - nBegin - 1);
	return left && right;
}
int main23()
{
	int str[] = { 5,7,6,9,11,10,8};
	cout << vertifySequenceOfBST(str, 7) << endl;
	system("pause");
	return 0;
}