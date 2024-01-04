#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int num;
	cin >> num;

	vector<string> arr;
	string tmp;
	for (int i = 0; i < num; i++)
	{
		cin >> tmp;
		arr.push_back(tmp);
	}

	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	sort(arr.begin(), arr.end(), [](string& a, string& b) -> bool {if (a.length() == b.length()) return a < b;  return a.length() < b.length(); });

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << '\n';
	}
}
