#include <iostream>

using namespace std;

int getC(int** arr, int n, int k)
{
	if (arr[n][k] != -1) return arr[n][k];
	else if (k < 0)
	{
		arr[n][k] = 0;
	}
	else if (k > n)
	{
		arr[n][k] = 0;
	}
	else if (k == 0)
	{
		arr[n][k] = 1;
	}
	else if (k == 1)
	{
		arr[n][k] = n;
	}
	else
	{
		arr[n][k] = getC(arr, n - 1, k - 1) + getC(arr, n - 1, k);
	}
	
	return arr[n][k];
}

int main()
{
	int n, k;
	cin >> n >> k;
	int** arr = new int*[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		arr[i] = new int[k + 1];
		for (int j = 0; j < k + 1; j++)
		{
			arr[i][j] = -1;
		}
	}

	cout << getC(arr, n, k);
}