#include <iostream>
#include <string>

using namespace std;

float FindMax(float* scores, int length)
{
	float max = 0;
	for (int i = 0; i < length; i++)
	{
		if (max < scores[i]) max = scores[i];
	}
	return max;
}

int main()
{
	int length = 0;
	cin >> length;
	float* scores = new float[length];
	for (int i = 0; i < length; i++)
	{
		cin >> scores[i];
	}

	float max = FindMax(scores, length);
	for (int i = 0; i < length; i++)
	{
		scores[i] = scores[i] / max * 100;
	}

	float sum = 0;
	for (int i = 0; i < length; i++)
	{
		sum += scores[i];
	}

	sum /= length;
	cout << sum;
}



