#include <iostream>
#include <string>
#include <cmath>

#define M 1234567891
#define R 31

using namespace std;

int main()
{
	int length;
	cin >> length;

	string str;
	cin >> str;

	unsigned long long answer = 0;
	unsigned long long powBuf = 1;
	for (int i = 0; i < length; i++)
	{
		answer = (answer + ((str[i] - 'a' + 1) * powBuf) % M) % M;
		powBuf = (powBuf * R) % M;
	}

	cout << answer % M;
	return 0;
}
