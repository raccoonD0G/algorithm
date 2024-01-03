#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool Checker(string targetStr)
{
	vector<char> tmpArr;
	for (int j = 0; targetStr[j] != '.'; j++)
	{
		if (targetStr[j] == '(')
		{
			tmpArr.push_back('(');
		}
		if (targetStr[j] == '[')
		{
			tmpArr.push_back('[');
		}
		if (targetStr[j] == ')')
		{
			if (tmpArr.size() == 0) return false;
			if (*(tmpArr.end() - 1) != '(') return false;
			else
			{
				tmpArr.erase(tmpArr.end() - 1);
			}
		}
		if (targetStr[j] == ']')
		{
			if (tmpArr.size() == 0) return false;
			if (*(tmpArr.end() - 1) != '[') return false;
			else
			{
				tmpArr.erase(tmpArr.end() - 1);
			}
		}
	}
	if (tmpArr.size() == 0) return true;
	else return false;
}

int main()
{
	vector<bool> boolArr;
	string tmp;
	while (true)
	{
		getline(cin, tmp);
		if (tmp == ".") break;
		boolArr.push_back(Checker(tmp));
	}

	for (int i = 0; i < boolArr.size(); i++)
	{
		if (boolArr[i]) cout << "yes\n";
		else cout << "no\n";
	}
}