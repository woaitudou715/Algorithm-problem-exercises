#include<bits/stdc++.h>
using namespace std;
//��һ�� c++stl
int GetNumberOfK1(vector<int> data, int k) {
	if (data.empty())
		return 0;
	auto resultpair = equal_range(data.begin(), data.end(),k);
	return resultpair.second - resultpair.first;
}
//�ڶ��� ��Ϊdata�ж������������Կ�����΢��һ�£���������k������λ�ã���������k-0.5��k+0.5
//��������Ӧ�ò����λ�ã�Ȼ��������ɡ�
int biSearch(const vector<int> & data, double num) {

	int s = 0, e = data.size() - 1;
	while (s <= e) {
		int mid = (e - s) / 2 + s;
		if (data[mid] < num)
			s = mid + 1;
		else if (data[mid] > num)
			e = mid - 1;
	}
	return s;
}
int GetNumberOfK2(vector<int> data, int k) {
	return biSearch(data, k + 0.5) - biSearch(data, k - 0.5);
}
//������ ���ֽⷨ �ҳ���һ��λ�ú����һ��λ���������
int GetFirstK(vector<int>data, int k, int start, int end)
{
	if (start > end)
		return -1;
	int middleIndex = (start + end) / 2;
	int middleData = data[middleIndex];
	if (middleData == k)
	{
		if (middleIndex > 0 && data[middleIndex - 1] != k || middleIndex == 0)
			return middleIndex;
		else
			end = middleIndex - 1;
	}
	else if (middleIndex > k)
		end = middleIndex - 1;
	else
		start = middleIndex + 1;
	return GetFirstK(data,k, start, end);
}
int GetLastK(vector<int>data, int k, int start, int end)
{
	if (start > end)
		return -1;
	int middleIndex = (start + end) / 2;
	int middleData = data[middleIndex];
	if (middleData == k)
	{
		if (middleIndex < data.size()-1 && data[middleIndex + 1] != k || middleIndex == data.size())
			return middleIndex;
		else
			start = middleIndex + 1;
	}
	else if (middleIndex > k)
		end = middleIndex - 1;
	else
		start = middleIndex + 1;
	return GetLastK(data, k, start, end);
}
int GetNumberOfK3(vector<int> data, int k) {
	if (data.empty())
		return 0;
	int number = 0;
	int first = GetFirstK(data, k, 0, data.size() - 1);
	int last = GetLastK(data, k, 0, data.size() - 1);
	if (first > -1 && last > -1)
		number = last - first + 1;
	return number;
}
int main37()
{
	vector<int> data;
	data.push_back(1);
	data.push_back(2);
	data.push_back(3);
	data.push_back(3);
	data.push_back(3);
	data.push_back(3);
	data.push_back(5);
	cout << GetNumberOfK3(data, 3) << endl;
	return 0;
}