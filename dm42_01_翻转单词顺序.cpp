#include<bits\stdc++.h>
using namespace std;
string ReverseSentence1(string str)
{
	string tmp;
	string result;
	stringstream input(str);
	stack<string> s;
	while (getline(input, tmp, ' '))
	{
		s.push(tmp);
	}
	while (!s.empty())
	{
		result += s.top();
		result += " ";
		s.pop();
	}
	result = result.substr(0, result.size() - 1);
	return result;
}

string ReverseSentence2(string str) {
	string res = "", tmp = "";
	for (unsigned int i = 0; i < str.size(); ++i) {
		if (str[i] == ' ') res = " " + tmp + res, tmp = "";
		else tmp += str[i];
	}
	if (tmp.size()) res = tmp + res;
	return res;
}
int main()
{
	string str = "I am a student.";
	string str1 = ReverseSentence1(str);
	string str2 = ReverseSentence2(str);
	if (str1 == str2)
		cout << 1 << endl;
	else
		cout << 0 << endl;
	return 0;
}