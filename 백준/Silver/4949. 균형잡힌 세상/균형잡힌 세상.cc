#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

bool Checker(string targetStr)
{
	stack<char> tmpArr;
	for (int j = 0; targetStr[j] != '.'; j++)
	{
		if (targetStr[j] == '(')
		{
			tmpArr.push('(');
		}
		if (targetStr[j] == '[')
		{
			tmpArr.push('[');
		}
		if (targetStr[j] == ')')
		{
			if (tmpArr.size() == 0) return false;
			if (tmpArr.top() != '(') return false;
			else
			{
				tmpArr.pop();
			}
		}
		if (targetStr[j] == ']')
		{
			if (tmpArr.size() == 0) return false;
			if (tmpArr.top() != '[') return false;
			else
			{
				tmpArr.pop();
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