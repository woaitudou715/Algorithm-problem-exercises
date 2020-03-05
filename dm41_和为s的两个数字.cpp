#include<bits\stdc++.h>
using namespace std;
struct pair1 {
	int num1;
	int num2;
};
bool cmp(pair1 a, pair1 b)
{
	return a.num1*a.num2 < b.num1*b.num2;
}
vector<int> FindNumbersWithSum(vector<int> array, int sum) {
	vector<int> result;
	if (array.empty())
		return result;
	vector<pair1> vec;
	pair1 tmp;
	int start = 0;
	int end = array.size() - 1;
	while (end > start)
	{
		if (array[start] + array[end] == sum)
		{
			tmp.num1 = array[start];
			tmp.num2 = array[end];
			vec.push_back(tmp);
			start++;
		}
		else if (array[start] + array[end] > sum)
			end--;
		else
			start++;
	}
	if (vec.empty())
		return result;

	sort(vec.begin(), vec.end(), cmp);
	result.push_back(vec[0].num1);
	result.push_back(vec[0].num2);
	return result;	
}
int main4101()
{
	vector<int> array;
	array.push_back(1);
	array.push_back(2);
	array.push_back(4);
	array.push_back(7);
	array.push_back(11);
	array.push_back(15);
	vector<int> res = FindNumbersWithSum(array, 15);
	
	return 0;
}