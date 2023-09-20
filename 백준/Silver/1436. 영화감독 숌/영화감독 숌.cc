#include <iostream>
#include <string>

using namespace std;

bool isInclud666(int input)
{
	string inputStr;
	inputStr = to_string(input);
	int count6 = 0;

	for (int i = 0; i < inputStr.length(); i++)
	{
		if (inputStr[i] == '6')
		{
			count6++;
			if (count6 == 3) return true;
		}
		else count6 = 0;
	}
	return false;
}

int main()
{
	int input;
	cin >> input;
	int result = 0;
	for (int i = 0; i != input; result++)
	{
		if (isInclud666(result) == true) i++;
	}
	cout << result - 1;
}

