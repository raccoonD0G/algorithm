#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int cardTmp;
	vector<int> cardArr;
	for (int i = 0; i < n; i++)
	{
		
		cin >> cardTmp;
		cardArr.push_back(cardTmp);
	}

	sort(cardArr.begin(), cardArr.end());

	int m;
	cin >> m;
	int searchTmp;
	vector<int> searchArr;
	for (int i = 0; i < m; i++)
	{
		cin >> searchTmp;
		searchArr.push_back(searchTmp);
	}

	for (int i = 0; i < m; i++)
	{
		pair<vector<int>::iterator, vector<int>::iterator> answer = equal_range(cardArr.begin(), cardArr.end(), searchArr[i]);
		cout << answer.second - answer.first << " ";
	}
}