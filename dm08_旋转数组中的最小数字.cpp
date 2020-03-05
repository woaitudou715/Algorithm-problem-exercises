#include<iostream>
#include<vector>
#include<stack>
using namespace std;
//快速排序算法
int Partition(int data[], int length, int start, int end)
{
	if (data == NULL || length <= 0 || start < 0 || end >= length)
		throw new std::exception("Invalid parameters");
	int index = start;
	swap(data[index], data[end]);
	int small = start - 1;
	for (int index = start; index < end; index++)
	{
		if (data[index] < data[end])
		{
			++small;
			if (small != index)
				swap(data[index], data[small]);
		}
	}
	++small;
	swap(data[small], data[end]);
	return small;
}
void QuickSort(int data[], int length, int start, int end)
{
	if (start == end)
		return;
	int index = Partition(data, length, start, end);
	if (index > start)
		Partition(data, length, start, index - 1);
	if (index < end)
		Partition(data, length, index + 1, end);
}
//对公司的员工年龄进行排序
void SortAge(int ages[],int length)
{
	if (ages == NULL || length <= 0)
		return;
	const int oldestAge = 99;
	int timesOfAge[oldestAge + 1];
	for (int i = 0; i <= oldestAge; ++i)
		timesOfAge[i] = 0;
	for (int i = 0; i < length; ++i)
	{
		int age = ages[i];
		++timesOfAge[age];
	}
	int index = 0;
	for (int i = 0; i <= oldestAge; ++i)
	{
		for (int j = 0; j < timesOfAge[i]; ++j)
		{
			ages[index] = i;
			++index;
		}
	}
}
//顺序查找 当数组中前后和中间的数相等时  本质上是二分查找  顺序查找的时间复杂度为n
int MinInorder(int* numbers, int index1, int index2)
{
	int result = numbers[index1];
	for (int i = index1 + 1; i <= index2; i++)
	{
		if (numbers[i] < result)
			result = numbers[i];
	}
	return result;
}
int FindMin(int* numbers, int length)
{
	if (numbers == NULL || length <= 0)
		throw new std::exception("Invalid parameters");
	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;
	while (numbers[index1] >= numbers[index2])
	{
		if (index1 - index2 == 1)
		{
			indexMid = index2;
			break;
		}
		indexMid = (index1 + index2) / 2;
		if (numbers[indexMid] >= numbers[index1])
			index1 = indexMid;
		else if(numbers[indexMid] <= numbers[index2])
			index2 = indexMid;
	}
	return numbers[indexMid];
}
int FindMin2(int* numbers, int length)
{
	if (numbers == NULL || length <= 0)
		throw new std::exception("Invalid parameters");
	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;
	while (numbers[index1] >= numbers[index2])
	{
		if (index1 - index2 == 1)
		{
			indexMid = index2;
			break;
		}
		indexMid = (index1 + index2) / 2;
		if (numbers[index1] == numbers[indexMid] && numbers[indexMid] == numbers[index2])
			return MinInorder(numbers, index1, index2);
		if (numbers[indexMid] >= numbers[index1])
			index1 = indexMid;
		else if (numbers[indexMid] <= numbers[index2])
			index2 = indexMid;
	}
	return numbers[indexMid];
}
int main8()
{
	system("pause");
	return 0;
}