#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//第一种解法 排序 中间数字即为所求 要排序时间复杂度为o(nlogn)
int MoreThanHalfNum_Solution1(vector<int> numbers) {
	sort(numbers.begin(), numbers.end());
	int n = (numbers.size() - 1) / 2;
	//求容器中特定字符出现的次数 count
	int num = count(numbers.begin(), numbers.end(), numbers[n]);
	if (num > n)
		return numbers[n];
	else
		return 0;
}

//第二种解法 如果有符合条件的数字，则它出现的次数比其他所有数字出现的次数和还要多。
//在遍历数组时保存两个值：一是数组中一个数字，一是次数。遍历下一个数字时，若它与之
//前保存的数字相同，则次数加1，否则次数减1；若次数为0，则保存下一个数字，并将次数置为1。
//遍历结束后，所保存的数字即为所求。然后再判断它是否符合条件即可。

//时间复杂度o(n)
int MoreThanHalfNum_Solution2(vector<int> numbers)
{
	if (numbers.empty())
		return 0;
	
	int num = numbers[0], count = 1;
	for (int i = 1; i < numbers.size(); i++)
	{
		if (count == 0)
		{
			num = numbers[i];
			count = 1;
		}
		else if (numbers[i] == num)
		{
			count++;
		}
		else
		{
			count--;
		}
	}
	count = 0;
	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == num)
			count++;
	}
	return (count * 2 > numbers.size()) ? num : 0;
}

//第三种解法 如果存在的话中位数即为所求，类似快排 判断下标是否为middle
int Partition(vector<int>& numbers, int length, int start, int end);
int MoreThanHalfNum_Solution3(vector<int> numbers) {
	if (numbers.empty())
		return 0;
	int length = numbers.size();
	int middle = length >> 1;
	int start = 0;
	int end = length - 1;
	int index = Partition(numbers, length, start, end);
	while (index != middle)
	{
		if (index > middle)
		{
			end = index - 1;
			index = Partition(numbers, length, start, end);
		}
		else
		{
			start = index + 1;
			index = Partition(numbers, length, start, end);
		}
	}

	int count = 0;
	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == numbers[middle])
			count++;
	}
	return (count * 2 > numbers.size()) ? numbers[middle] : 0;
}
int Partition(vector<int>& numbers, int length, int start, int end)
{
	if (numbers.empty() || length <= 0 || start > end)
		return 0;
	int pivot = numbers[start];
	
	while (start < end)
	{
		while (start < end && numbers[end] >= pivot)
			end--;
		numbers[start] = numbers[end];

		while (start < end && numbers[start] <= pivot)
			start++;
		numbers[end] = numbers[start];
	}
	numbers[start] = pivot;
	return start;
}
int main()
{
	vector<int> vec;
	
	vec.push_back(5);
	vec.push_back(8);
	vec.push_back(1);
	vec.push_back(8);
	vec.push_back(8);
	vec.push_back(6);
	vec.push_back(8);
	vec.push_back(8);
	int result = MoreThanHalfNum_Solution3(vec);
	cout << result << endl;
	system("pause");
	return 0;
}