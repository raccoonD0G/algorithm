#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_HIGHT 256
#define INT_MAX 2147483647

using namespace std;


class Level
{
public:
	int level;
	int timeNeeded;
};
int main()
{
	int n, m, b;

	cin >> n >> m >> b;

	vector<vector<int>> ground(n);
	vector<Level> levelArr(MAX_HIGHT + 1);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int tmp;
			cin >> tmp;
			ground[i].push_back(tmp);
		}
	}

	for (int level = 0; level < MAX_HIGHT + 1; level++)
	{
		int timeSum = 0;
		int blockInInv = b;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if ((ground[i][j] - level) > 0)
				{
					blockInInv += ground[i][j] - level;
					timeSum += (ground[i][j] - level) * 2;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (timeSum != INT_MAX)
			{
				for (int j = 0; j < m; j++)
				{
					if ((ground[i][j] - level) < 0)
					{
						blockInInv -= level - ground[i][j];
						if (blockInInv >= 0) timeSum += (level - ground[i][j]);
						else
						{
							timeSum = INT_MAX;
							break;
						}
					}
				}
			}

		}
		levelArr[level].timeNeeded = timeSum;
		levelArr[level].level = level;
	}

	reverse(levelArr.begin(), levelArr.end());

	auto answerIterator = min_element(levelArr.begin(), levelArr.end(), [](Level a, Level b) -> bool {return a.timeNeeded < b.timeNeeded; });
	cout << (*answerIterator).timeNeeded << " " << (*answerIterator).level;
}