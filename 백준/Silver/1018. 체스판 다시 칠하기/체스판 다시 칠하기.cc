#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int checker(char** arr, int r, int c)
{
	int countB = 0;
	int countC = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i + j) % 2 == 0 && arr[r + i][c + j] == 'W') countB++;
			else if ((i + j) % 2 == 1 && arr[r + i][c + j] == 'B') countB++;
		}
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i + j) % 2 == 0 && arr[r + i][c + j] == 'B') countC++;
			else if ((i + j) % 2 == 1 && arr[r + i][c + j] == 'W') countC++;
		}
	}
	return min(countB, countC);
}

int main()
{
	int row, column;
	cin >> row >> column;

	char** arr;

	arr = new char*[row];
	for (int i = 0; i < row; i++)
	{
		arr[i] = new char[column];
	}

	for (int i = 0; i < row; i++)
	{
		cin >> arr[i];
	}

	vector<int> checkArr;

	for (int i = 0; i < row - 7; i++)
	{
		for (int j = 0; j < column - 7; j++)
		{
			checkArr.push_back(checker(arr, i, j));
		}
	}

	cout << *min_element(checkArr.begin(), checkArr.end());
}