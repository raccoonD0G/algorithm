#include <iostream>
#include <algorithm>

using namespace std;

int GetNum(int** arr, int k, int n)
{
	if (arr[k][n] != -1)
	{
		return arr[k][n];
	}
	else
	{
		int answer = 0;
		answer = GetNum(arr, k - 1, n) + GetNum(arr, k, n - 1);
		arr[k][n] = answer;
		return answer;
	}
}

int main()
{
	int** arr;

	int t;
	int* k;
	int* n;

	cin >> t;

	k = new int[t];
	n = new int[t];

	for(int i = 0; i < t; i++)
	{
		cin >> k[i];
		cin >> n[i];
		n[i]--;
	}

	int maxK = *max_element(k, k + t);

	arr = new int* [maxK + 1];
	for (int i = 0; i < maxK + 1; i++) arr[i] = new int[14];

	for (int i = 0; i < maxK + 1; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			if (i != 0) arr[i][j] = -1;
		}
	}
	for (int j = 0; j < 14; j++)
	{
		arr[0][j] = j + 1;
	}
	for (int i = 0; i < maxK + 1; i++)
	{
		arr[i][0] = 1;
	}

	for (int i = 0; i < t; i++)
	{
		cout << GetNum(arr, k[i], n[i]) << '\n';
	}
}