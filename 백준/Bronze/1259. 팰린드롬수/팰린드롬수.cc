#include <iostream>

using namespace std;

int main()
{
	string input;
	bool isSame = true;
	while (1)
	{
		isSame = true;
		cin >> input;
		if (input[0] == '0' && input.length() == 1) break;
		for (int i = 0; (input.length() - i - 1) > i; i++)
		{
			if (input[i] != input[input.length() - i - 1]) isSame = false;
		}
		if (isSame == true) cout << "yes\n";
		else cout << "no\n";
	}
}