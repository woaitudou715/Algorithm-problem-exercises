#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;
class my_compare_
{
public:
	bool operator()(int a, int b)
	{
		return a > b;
	}
};
int main()
{
	/*int n, d,position,value;
	cin >> n >> d;
	multimap<int, int,my_compare_> m_map;
	for (int i = 0; i < n; i++)
	{
		cin >> position >> value;
		m_map.insert(make_pair(position, value));
	}
	multimap<int, int>::iterator it = m_map.begin();
	multimap<int, int>::iterator it1;
	set<int> buf;
	for(;it != m_map.end();it++)
	{
		for(it1 = ++it;it1!=m_map.end();it1++)
		if (it != m_map.end())
		{
			if (abs((*it).first - (*it1).first) >= d)
				buf.insert((*it).second + (*it1).second);
		}
	}
	cout << *buf.rbegin() << endl;*/
	//system("pause");
	
	char a = 'a';
	char A = a + 32;
	cout << A;
	system("pause");
	return 0;
}