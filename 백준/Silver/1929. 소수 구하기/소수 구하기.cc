#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>


int main()
{
	int start, end;
	std::cin >> start >> end;
	std::vector<bool> boolArr(end + 1, true);
	boolArr[0] = boolArr[1] = 0;

	for (int i = 2; i * i <= end; i++)
	{
		if(boolArr[i]) for (int j = i * i; j <= end; j += i) boolArr[j] = false;
	}

	for (int i = start; i <= end; i++) if (boolArr[i]) std::cout << i << '\n';
}