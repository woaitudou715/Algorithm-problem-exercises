#include<bits\stdc++.h>
using namespace std;
vector<vector<int> > FindContinuousSequence(int sum) {
	vector<vector<int>> result;
	
	int start = 1;
	int end = 2;
	
	int cursum = start + end;
	while (start <= sum / 2)
	{
		while (cursum > sum && start <= sum / 2)
		{
			cursum -= start;
			start++;
		}

		if (cursum == sum)
		{
			vector<int> tmp;
			for (int j = start; j <= end; j++)
			{
				tmp.push_back(j);
			}
			result.push_back(tmp);
		}
		end++;
		cursum += end;
	}
	return result;
}
int main()
{
	FindContinuousSequence(15);
	return 0;
}