#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool DoStacking(int* target, int index, int length, stack<int>* stack, string* answer, int* count)
{
	if (index >= length) return true;
	if (*count > target[index] && stack->top() != target[index])
	{
		cout << "NO";
		return false;
	}
	
	while (target[index] >= *count)
	{
		answer->append("+");
		stack->push(*count);
		(*count)++;
	}
	answer->append("-");
	stack->pop();
	return DoStacking(target, index + 1, length, stack, answer, count);
}

int main()
{
	int length = 0;
	cin >> length;
	int* target = new int[length];
	string answer;

	stack<int> stack;
	int count = 1;

	for (int i = 0; i < length; i++)
	{
		cin >> target[i];
	}

	if(!DoStacking(target, 0, length, &stack, &answer, &count)) return 0;

	for (int i = 0; i < answer.length(); i++)
	{
		cout << answer[i] << "\n";
	}
}