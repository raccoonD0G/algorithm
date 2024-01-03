#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool Checker(string str)
{
	int count = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			count++;
		}
		else if (str[i] == ')')
		{
			count--;
			if (count < 0) return false;
		}
	}
	if (count == 0) return true;
	else return false;
}

int main()
{
	int num;
	cin >> num;
	vector<string> strArr;

	cin.ignore();

	for (int i = 0; i < num; i++)
	{
		string tmp;
		getline(cin, tmp);
		strArr.push_back(tmp);
	}

	for (int i = 0; i < num; i++)
	{
		if (Checker(strArr[i]) == true) cout << "YES\n";
		else cout << "NO\n";
	}
	
}