#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	int n;
	cin >> n;

	vector<int> numVector;

	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		numVector.push_back(tmp);
	}

	sort(numVector.begin(), numVector.end());

	for (int i = 0; i < n; i++)
	{
		cout << numVector[i] << " ";
	}
}
