#include<iostream>
#include<vector>
using namespace std;
bool Find(int* matrix, int rows, int columns, int num)
{
	bool found = false;
	if (matrix == NULL || rows < 0 || columns < 0)
		return false;
	int row = 0, column = columns - 1;
	while (column >= 0 && row <= rows - 1)
	{
		if (matrix[row * column + column] == num)
		{
			found = true;
			break;
		}
			
		else if (matrix[row*column + column] > num)
			--column;
		else
			++row;
	}
	return found;
}
bool Find(int target, vector<vector<int> > array) {
	if (array.empty())
		return false;
	bool found = false;
	int rows = array.size();
	int columns = array[0].size();
	int row = 0;
	int column = columns - 1;
	while (row < rows && column >= 0)
	{
		if (array[row][column] == target)
		{
			found = true;
			break;
		}
		else if (array[row][column] > target)
			--column;
		else
			++row;
	}
	return found;
}
int main01()
{
	system("pause");
	return 0;
}