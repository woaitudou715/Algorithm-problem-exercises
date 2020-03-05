#include<bits/stdc++.h>
using namespace std;
//第一种 记录0的个数，判断后续是否连续 不连续和零的个数相比较
bool IsContinuous1(vector<int> numbers) {
	int n = numbers.size();
	int numofzero = 0;
	int i, j;
	bool res = true;
	sort(numbers.begin(), numbers.end());
	for (i = 0; i < n; i++)
	{
		if (numbers[i] == 0)
			numofzero++;
		else
			break;
	}
	for (j = i + 1; j < n; i++,j++)
	{
		if (numbers[j] == numbers[i] + 1)
			continue;
		else {
			if (numbers[j] == numbers[i] || (numbers[j] - numbers[i] - 1) > numofzero)
			{
				res = false;
				break;
			}
			else {
				numofzero -= (numbers[j] - numbers[i] - 1);
			}
		}
	}
	return res;
}
// 
bool IsContinuous2(vector<int> numbers) {
	if (numbers.empty()) return 0;
	int count[14] = { 0 };//记录每个元素出现的次数;以numbers中的元素作为下标(最大K,对应13)
	int len = numbers.size();
	int max = -1;
	int min = 14;

	for (int i = 0; i < len; ++i)
	{
		count[numbers[i]]++;
		if (numbers[i] == 0) continue;

		if (count[numbers[i]] > 1) return 0;

		if (numbers[i] > max) max = numbers[i];

		if (numbers[i] < min) min = numbers[i];

	}//end for

	if (max - min < 5) return 1;

	return 0;

}//end IsContinuous()
int main()
{
	vector<int> vec;
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	cout << IsContinuous2(vec) << endl;
	system("pause");
	return 0;
}