#include<iostream>
#include<map>
#include<vector>
#include<set>
// 第一种会修改输入的数组 类似借鉴快排的操作
using namespace std;
int Partition(vector<int>& input,int start,int end)
{
	int pivotval = input[start];
	while (start < end)
	{
		while(input[end] >= pivotval && start < end)
			end--;
		input[start] = input[end];

		while (input[start] <= pivotval && start < end)
			start++;
		input[end] = input[start];

		
	}
	input[start] = pivotval;
	return start;
}
vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
	
	vector<int> result;
	if (input.empty())
		return result;
	int n = input.size();
	int start = 0;
	int end = n - 1;
	int index = Partition(input, start, end);
	while (index != k - 1)
	{
		if (index > k - 1)
		{
			end = index - 1;
			if(end > 0)
				index = Partition(input, start, end);
		}
		else
		{
			start = index + 1;
			if(start < n)
				index = Partition(input, start, end);
		}
	}
	for (int i = 0; i < k; i++)
	{
		result.push_back(input[i]);
	}
	return result;
}
//第二种 直接排序 时间复杂读较高

//第三种 


vector<int> GetLeastNumbers_Solution1(vector<int> input, int k) {
	
	vector<int> result;
	if (input.empty() || k <= 0 || k > input.size())
		return result;
	multiset<int, greater<int>> intSet;
	intSet.clear();
	auto it = input.begin();
	for (; it != input.end(); it++)
	{
		if (intSet.size() < k)
			intSet.insert(*it);
		else
		{
			auto head = intSet.begin();
			if (*it < *head)
			{
				intSet.erase(head);
				intSet.insert(*it);
			}
		}
	}
	
	for (auto it = intSet.rbegin(); it != intSet.rend(); it++)
	{
		result.push_back(*it);
	}
	return result;
}
int main30()
{
	vector<int> vec;
	vec.push_back(5);
	vec.push_back(4);
	vec.push_back(6);
	vec.push_back(7);
	vec.push_back(3);
	vec.push_back(8);
	vec.push_back(9);
	vec.push_back(2);
	vec.push_back(1);
	vec.push_back(10);
	vector<int> ans = GetLeastNumbers_Solution1(vec, 5);
	for (auto it : ans)
		cout << it << " ";
	system("pause");
	return 0;
}