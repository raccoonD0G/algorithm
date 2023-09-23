#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>



int main()
{
	
	int length = 0;
	std::cin >> length;

	std::vector<int> arr(length);
	int min = 0;
	int max = 0;

	std::map<int, int> freq;
	std::priority_queue<int, std::vector<int>, std::greater<int>> freqQueue;


	for (int i = 0; i < length; i++)
	{
		std::cin >> arr[i];
		if (i == 0)
		{
			min = arr[0];
			max = arr[0];
		}
		else
		{
			if (arr[i] < min) min = arr[i];
			if (arr[i] > max) max = arr[i];
		}
		freq[arr[i]]++;
	}

	int output0 = 0;
	for (int i = 0; i < length; i++)
	{
		output0 += arr[i];
	}
	output0 = std::round((double)output0 / (double)length);
	std::cout << output0 << '\n';

	std::sort(arr.begin(), arr.end());
	int output1 = arr[length / 2];
	std::cout << output1 << '\n';

	int output2 = 0;
	int maxFreq = 0;
	for (int i = 0; i < length; i++)
	{
		if (freq[arr[i]] > maxFreq)
		{
			maxFreq = freq[arr[i]];
			while (!freqQueue.empty())freqQueue.pop();
			freqQueue.push(arr[i]);
		}
		else if (freq[arr[i]] == maxFreq)
		{
			freqQueue.push(arr[i]);
		}
	}
	int lastPop = 0;
	if (freqQueue.size() == 1)
	{
		output2 = freqQueue.top();
	}
	else
	{
		lastPop = freqQueue.top();
		freqQueue.pop();
		while (lastPop == freqQueue.top() && freqQueue.size() != 1) freqQueue.pop();
		output2 = freqQueue.top();
	}

	std::cout << output2 << '\n';

	int output3 = max - min;
	std::cout << output3;

	return 0;
}