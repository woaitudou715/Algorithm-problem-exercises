#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

vector<int> printMatrix(vector<vector<int> > matrix) {
	vector<int> vec;
	int row = matrix.size();
	int column = matrix[0].size();
	int leftSide = 0, rightSide = column - 1, topSide = 0, bottomSide = row - 1;
	while (leftSide <= rightSide && topSide <= bottomSide)
	{
		for (int i = leftSide; i <= rightSide; i++)
			vec.push_back(matrix[topSide][i]);
		if (topSide < bottomSide)
		{
			for (int i = topSide + 1; i <= bottomSide; i++)
				vec.push_back(matrix[i][rightSide]);
		}
		if (topSide < bottomSide && rightSide > leftSide)
		{
			for (int i = rightSide - 1; i >= leftSide; i--)
				vec.push_back(matrix[bottomSide][i]);
		}
		if (topSide < bottomSide - 1 && leftSide < rightSide)
		{
			for (int i = bottomSide - 1; i > topSide; i--)
				vec.push_back(matrix[i][leftSide]);
		}
		++topSide, ++leftSide, --rightSide, --bottomSide;
	}
	return vec;
}
int main()
{
	vector<vector<int>> matrix(4,vector<int>(4,0));
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			matrix[i][j] = 4 * i + j + 1;
		}
	}
	vector<int> result = printMatrix(matrix);
	for (auto it : result)
		cout << it << " ";
	return 0;
}
