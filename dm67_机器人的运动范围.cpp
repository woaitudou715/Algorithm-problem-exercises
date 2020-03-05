#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
int getDigitSum(int number)
{
	int result = 0;
	while (number)
	{
		result += number % 10;
		number /= 10;
	}
	return result;
}
bool check(int threshold, int rows, int cols, int row, int col, bool*visited)
{
	if (row >= 0 && row < rows && col >= 0 && col < cols
		&& getDigitSum(row) + getDigitSum(col) <= threshold
		&& !visited[row * cols + col])
	{
		return true;
	}
	return false;
}
int movingCountCore(int threshold, int rows, int cols, int row, int col, bool*visited)
{
	int count = 0;
	if (check(threshold, rows, cols, row, col, visited))
	{
		visited[row*cols + col] = true;
		count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited)
			+ movingCountCore(threshold, rows, cols, row, col - 1, visited)
			+ movingCountCore(threshold, rows, cols, row + 1, col, visited)
			+ movingCountCore(threshold, rows, cols, row, col + 1, visited);
	}
	return count;
}
int movingCount(int threshold, int rows, int cols)
{
	bool* visited = new bool[rows * cols];
	memset(visited, false, rows*cols);
	int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
	delete[] visited;
	return count;
}

int main67()
{
	system("pause");
	return 0;
}