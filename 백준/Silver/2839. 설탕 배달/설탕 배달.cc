#include <iostream>

using namespace std;

int main()
{
	int num;
	cin >> num;

	int fiveKgNum = num / 5;
	int threeKgNum = 0;

	switch (num % 5)
	{
	case 0:
		break;
	case 1:
		threeKgNum += 2;
		fiveKgNum -= 1;
		break;
	case 2:
		threeKgNum += 4;
		fiveKgNum -= 2;
		break;
	case 3:
		threeKgNum += 1;
		break;
	case 4:
		threeKgNum += 3;
		fiveKgNum -= 1;
		break;
	}

	if (threeKgNum < 0 || fiveKgNum < 0) cout << -1;
	else cout << threeKgNum + fiveKgNum;
}