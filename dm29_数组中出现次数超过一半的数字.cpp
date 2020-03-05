#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//��һ�ֽⷨ ���� �м����ּ�Ϊ���� Ҫ����ʱ�临�Ӷ�Ϊo(nlogn)
int MoreThanHalfNum_Solution1(vector<int> numbers) {
	sort(numbers.begin(), numbers.end());
	int n = (numbers.size() - 1) / 2;
	//���������ض��ַ����ֵĴ��� count
	int num = count(numbers.begin(), numbers.end(), numbers[n]);
	if (num > n)
		return numbers[n];
	else
		return 0;
}

//�ڶ��ֽⷨ ����з������������֣��������ֵĴ����������������ֳ��ֵĴ����ͻ�Ҫ�ࡣ
//�ڱ�������ʱ��������ֵ��һ��������һ�����֣�һ�Ǵ�����������һ������ʱ��������֮
//ǰ�����������ͬ���������1�����������1��������Ϊ0���򱣴���һ�����֣�����������Ϊ1��
//��������������������ּ�Ϊ����Ȼ�����ж����Ƿ�����������ɡ�

//ʱ�临�Ӷ�o(n)
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

//�����ֽⷨ ������ڵĻ���λ����Ϊ�������ƿ��� �ж��±��Ƿ�Ϊmiddle
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