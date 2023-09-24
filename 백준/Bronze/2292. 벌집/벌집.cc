#include <iostream>
#include <string>


int main()
{
	int n;
	std::cin >> n;

	int line = 1;
	int i = 1;
	for (i = 1; n > line; i++) line = line + (6 * i);
	std::cout << i;
}