#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int length;
	cin >> length;

	string str;
	cin >> str;

	int answer = 0;
	for (int i = 0; i < length; i++)
	{
		answer += (str[i] - 'a' + 1) * pow(31, i);
	}

	cout << answer;
}