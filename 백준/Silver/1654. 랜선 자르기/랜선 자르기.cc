#include <iostream>

using namespace std;

int main()
{
	unsigned int arrLength = 0;
	unsigned int needs;
	cin >> arrLength;
	cin >> needs;
	unsigned int* arr = new unsigned int[arrLength];
	for (unsigned int i = 0; i < arrLength; i++)
	{
		cin >> arr[i];
	}
	
	unsigned int max = 0;
	for (unsigned int i = 0; i < arrLength; i++)
	{
		if (max < arr[i]) max = arr[i];
	}
	
	unsigned int least = 0;
	unsigned int searchPoint;
	unsigned int count;
	while(least <= max)
	{
		searchPoint = (max + least) / 2;
		count = 0;
		for (unsigned int i = 0; i < arrLength; i++)
		{
			if (searchPoint == 0)
			{
				cout << '1';
				return 0;
			}
			
			count += (arr[i] / searchPoint);
		}
		if (count >= needs)
		{
			least = searchPoint + 1;
		}
		else
		{
			max = searchPoint - 1;
		}
	}
	cout << least - 1;
	delete[] arr;
}