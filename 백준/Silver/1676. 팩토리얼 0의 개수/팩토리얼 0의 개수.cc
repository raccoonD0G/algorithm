#include <iostream>
#include <string>

using namespace std;

int min(int a, int b)
{
	if (a < b) return a;
	else return b;
}
int main()
{
	int num;
	int countTwo = 0;
	int countFive = 0;
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		if (i % 2 == 0)
		{
			int buffer = i;
			while (buffer % 2 == 0)
			{
				buffer /= 2;
				countTwo++;
			}
		}
		if (i % 5 == 0)
		{
			int buffer = i;
			while (buffer % 5 == 0)
			{
				buffer /= 5;
				countFive++;
			}
		}
	}
	
	cout << min(countTwo, countFive);
}