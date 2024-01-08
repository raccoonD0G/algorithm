#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int inputLength;
	cin >> inputLength;

	if (inputLength == 0)
	{
		cout << 0;
		return 0;
	}
	vector<int> inputArr(inputLength);

	for (int i = 0; i < inputArr.size(); i++)
	{
		cin >> inputArr[i];
	}

	sort(inputArr.begin(), inputArr.end());

	int lowEnd = round((double)inputLength * 0.15);
	int highEnd = inputLength - lowEnd;
	
	unsigned long long sum = 0;
	for (int i = lowEnd; i < highEnd; i++)
	{
		sum += inputArr[i];
	}

	cout << round((double)sum / (double)(highEnd - lowEnd));
	return 0;
}