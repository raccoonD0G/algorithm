#include <iostream>
#include <vector>
using namespace std;

int JosephusPermutation(vector<int>& arr, int startIndex, int k)
{
	if (arr.size() == 0) return -1;

	int targetIndex = startIndex + k - 1;
	int answer;

	while (targetIndex >= arr.size()) targetIndex -= arr.size();
	answer = arr[targetIndex];
	arr.erase(arr.begin() + targetIndex);

	cout << answer + 1;
	if (arr.size() != 0) cout << ", ";
	return targetIndex;
}

int main()
{
	int n;
	int k;
	cin >> n >> k;

	vector<int> arr(n);

	for (int i = 0; i < n; i++)
	{
		arr[i] = i;
	}

	int startIndex = 0;
	cout << "<";
	while ((startIndex = JosephusPermutation(arr, startIndex, k)) != -1);
	cout << ">";
}