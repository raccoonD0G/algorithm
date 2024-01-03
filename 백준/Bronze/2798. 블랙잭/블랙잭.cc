#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;

	cin >> n;
	cin >> m;

	vector<int> numArr;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		numArr.push_back(tmp);
	}

	vector<vector<int>> cassArr;
	vector<int> tmpArr;
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				tmpArr.clear();
				tmpArr.push_back(i);
				tmpArr.push_back(j);
				tmpArr.push_back(k);
				cassArr.push_back(tmpArr);
			}
		}
	}

	vector<int> sumArr;

	for (int i = 0; i < cassArr.size(); i++)
	{
		sumArr.push_back(numArr[cassArr[i][0]] + numArr[cassArr[i][1]] + numArr[cassArr[i][2]]);
	}

	sort(sumArr.begin(), sumArr.end());

	int max = 0;

	for (int i = 0; i < sumArr.size(); i++)
	{
		if (sumArr[i] > max) max = sumArr[i];
		if (sumArr[i] > m)
		{
			cout << sumArr[i - 1];
			exit(0);
		}
	}
	cout << max;
}