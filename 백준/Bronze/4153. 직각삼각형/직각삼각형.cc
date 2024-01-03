#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<vector<int>> arr;

	int tmpInt;
	vector<int> tmp;
	while (true)
	{
		tmp.clear();
		for (int i = 0; i < 3; i++)
		{
			cin >> tmpInt;
			tmp.push_back(tmpInt);
		}

		if (tmp[0] == 0 && tmp[1] == 0 && tmp[2] == 0) break;
		else
		{
			swap(*max_element(tmp.begin(), tmp.end()), tmp[0]);
			arr.push_back(tmp);
		}
	}

	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i][0] * arr[i][0] == arr[i][1] * arr[i][1] + arr[i][2] * arr[i][2]) cout << "right\n";
		else cout << "wrong\n";
	}
}