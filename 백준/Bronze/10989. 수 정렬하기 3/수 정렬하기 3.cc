#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);


	int num;
	cin >> num;

	int* arr = new int[10001];
	int tmp;

	for (int i = 0; i < 10001; i++)
	{
		arr[i] = 0;
	}

	for (int i = 0; i < num; i++)
	{
		cin >> tmp;
		arr[tmp]++;
	}

	for (int i = 0; i < 10001; i++)
	{
		for (int j = 0; j < arr[i]; j++)
		{
			cout << i << "\n";
		}
	}

	delete[] arr;
}