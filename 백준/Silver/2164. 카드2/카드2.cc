#include <iostream>
#include <queue>

int main()
{
	int n;
	std::cin >> n;

	std::queue<int> q;

	for (int i = 0; i != n; i++)
	{
		q.push(i);
	}

	while (q.size() != 1)
	{
		q.pop();
		if (q.size() != 1)
		{
			q.push(q.front());
			q.pop();
		}
	}

	std::cout << q.front() + 1;
}