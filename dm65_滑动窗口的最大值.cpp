#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

vector<int> maxInWindows1(const vector<int>& num, unsigned int size)
{
	vector<int> result;
	if (num.size() >= size && size >= 1)
	{
		deque<int> index;
		for (unsigned int i = 0; i < size; i++)
		{
			while (!index.empty() && num[i] >= num[index.back()])
				index.pop_back();
			index.push_back(i);
		}
		for (unsigned int i = size; i < num.size(); i++)
		{
			result.push_back(num[index.front()]);
			while (!index.empty() && num[i] >= num[index.back()])
				index.pop_back();
			if (!index.empty() && index.front() <= (int)(i - size))
				index.pop_front();
			index.push_back(i);
		}
		result.push_back(num[index.front()]);
	}
	return result;
}
vector<int> maxInWindows2(const vector<int>& num, unsigned int size)
{
	vector<int> res;
	deque<int> s;
	for (unsigned int i = 0; i < num.size(); ++i) {
		while (s.size() && num[s.back()] <= num[i])//�Ӻ������ε��������бȵ�ǰnumֵС��Ԫ�أ�ͬʱҲ�ܱ�֤������Ԫ��Ϊ��ǰ�������ֵ�±�
			s.pop_back();
		while (s.size() && i - s.front() + 1 > size)//����ǰ�����Ƴ�����Ԫ�����ڵ�λ�ã�������Ԫ�������Ӧ��num���ڴ����У���Ҫ����
			s.pop_front();
		s.push_back(i);//��ÿ�λ�����num�±�������
		if (size && i + 1 >= size)//�����������׵�ַi���ڵ���sizeʱ�ſ�ʼд�봰�����ֵ
			res.push_back(num[s.front()]);
	}
	return res;
}

vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
	vector<int> result;
	if (num.size() >= size && size >= 1)
	{
		int m;
		for (int i = 0; i < num.size() - size + 1; i++)
		{
			m = num[i];
			for (int j = i + 1; j < i + size; j++)
			{
				if (num[j] > m)
					m = num[j];
			}
			result.push_back(m);
		}
	}
	return result;
}
int main65()
{
	int arr[] = { 2,3,4,2,6,2,5,1 };
	vector<int> ia(arr, arr + 8);
	vector<int> result = maxInWindows2(ia, 3);
	for (auto it : result)
		cout << it << " ";
	cout << endl;
	system("pause");
	return 0;
}
