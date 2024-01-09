#include <iostream>

using namespace std;

int getGreatestCommonDivisor(int a, int b)
{
	while (true)
	{
		if (a > b)
		{
			a %= b;
			if (a == 0) return b;
		}
		else
		{
			b %= a;
			if (b == 0) return a;
		}
	}
}

int getLeastCommonMultiple(int a, int b, int gCD)
{
	return (a * b) / gCD;
}

int main()
{
	int a, b;
	cin >> a >> b;

	int gCD = getGreatestCommonDivisor(a, b);
	cout << gCD << "\n";
	cout << getLeastCommonMultiple(a, b, gCD);
}