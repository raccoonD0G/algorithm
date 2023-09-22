#include <iostream>
#include <vector>



int main()
{
	int length = 0;
	std::cin >> length;

	std::vector<int> arr(length);
	for (int i = 0; i < length; i++)
	{
		std::cin >> arr[i];
	}

	std::vector<bool> boolArr(1001, true);
	boolArr[0] = boolArr[1] = 0;
	for (int i = 2; i * i <= 1000; i++)
	{
		for (int j = i * i; j <= 1000; j += i) boolArr[j] = false;
	}

	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (boolArr[arr[i]]) count++;
	}

	std::cout << count;
	return 0;
}