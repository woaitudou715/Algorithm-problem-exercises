#include<iostream>
#include<vector>
using namespace std;
int FindGreatestSumOfSubArray(vector<int> array) {
	if (array.empty())
		return 0;
	int greatestSum = array[0];
	int sum = array[0];
	for (auto it = array.begin()+1;it != array.end();it++)
	{
		sum += *it;
		if (sum  < *it)
			sum = *it;
		
		if (sum > greatestSum)
			greatestSum = sum;
	}
	return greatestSum;
}
int FindGreatestSumOfSubArray2(vector<int> array) {

	int cursum = array[0];
	int maxsum = array[0];
	for (int i = 1; i < array.size(); i++) {
		cursum += array[i];
		if (cursum < array[i])
			cursum = array[i];

		if (cursum > maxsum)
			maxsum = cursum;
	}
	return maxsum;
}
int main31()
{
	vector<int> vec;
	vec.push_back(-2);
	vec.push_back(-8);
	vec.push_back(-1);
	vec.push_back(-5);
	vec.push_back(-9);
	/*vec.push_back(7);
	vec.push_back(2);
	vec.push_back(-5);*/
	cout << FindGreatestSumOfSubArray(vec) << endl;
	system("pause");
	return 0;
}