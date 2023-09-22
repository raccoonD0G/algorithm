#include <iostream>
#include <vector>

int GetFirstTrue(std::vector<bool>& boolArr, int end)
{
	for (int i = 0; i < end; i++) if (boolArr[i] == true) return i;
}

int FindMax(std::vector<int>& arr, std::vector<bool>& boolArr, int start, int end)
{
	int maxIndex = GetFirstTrue(boolArr, end);
	for (int i = start; i < end; i++)
	{
		if (boolArr[i] && arr[maxIndex] < arr[i]) maxIndex = i;
	}
	return maxIndex;
}
int main()
{
	int tryNum = 0;
	int paperNum = 0;
	int targetOrder = 0;
	int count = 0;

	int start = 0;

	std::vector<int> arr;
	std::vector<bool> boolArr;
	std::vector<int> answer;

	std::cin >> tryNum;
	for (int i = 0; i < tryNum; i++)
	{
		std::cin >> paperNum >> targetOrder;
		arr.clear();
		arr.resize(paperNum);
		boolArr.clear();
		boolArr.resize(paperNum);
		count = 0;
		start = 0;

		for (int j = 0; j < paperNum; j++) boolArr[j] = true;
		for (int j = 0; j < paperNum; j++) std::cin >> arr[j];

		for (int j = 0; j < arr.size(); j++)
		{
			int maxIndex = FindMax(arr, boolArr, start, arr.size());
			if (maxIndex == start)
			{
				if (start == targetOrder) break;
				else
				{
					boolArr[j] = false;
					count++;
					start++;
				}
			}
			else
			{
				arr.push_back(arr[j]);
				boolArr.push_back(true);
				boolArr[j] = false;
				if (start == targetOrder) targetOrder = arr.size() - 1;
				start++;
				
			}
		}
		
		answer.push_back(count);
	}

	for (int i = 0; i < answer.size(); i++)
	{
		std::cout << answer[i] + 1 << '\n';
	}

	return 0;
}