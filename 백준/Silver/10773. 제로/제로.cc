#include <iostream>
#include <stack>

using namespace std;
int main()
{
	int num;
	stack<int> mStack;
	cin >> num;

	mStack.push(-1);
	for (int i = 0; i < num; i++)
	{
		int tmp;
		cin >> tmp;
		if (tmp == 0)
		{
			mStack.pop();
		}
		else
		{
			mStack.push(tmp);
		}
	}

	int answer = 0;
	while (mStack.top() != -1)
	{
		answer += mStack.top();
		mStack.pop();
	}

	cout << answer;
}