#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int BFS(vector<vector<int>>& graphVec, queue<int>& bFSVec, vector<bool>& isCheckedVec, int count)
{
    int bFSVecLength = 0;
    while (bFSVec.empty() == false)
    {
        bFSVecLength = bFSVec.size();
        for (int i = 0; i < bFSVecLength; i++)
        {
            for (int j = 0; j < graphVec[bFSVec.front()].size(); j++)
            {
                int tmp = graphVec[bFSVec.front()][j];
                if (tmp == 1) return ++count;
                else
                {
                    if (isCheckedVec[tmp] == false)
                    {
                        isCheckedVec[tmp] = true;
                        bFSVec.push(tmp);
                    }
                }
            }
            bFSVec.pop();
        }
        count++;
    }
    return 0;
}


int main()
{
    int inputNum = 0;
    cin >> inputNum;

    vector<vector<int>> graphVec(inputNum + 1);

    for (int i = 1; i < inputNum + 1; i++)
    {
        if (i != 1) graphVec[i].push_back(i - 1);
        if (i % 2 == 0) graphVec[i].push_back(i / 2);
        if (i % 3 == 0) graphVec[i].push_back(i / 3);
    }

    queue<int> bFSVec;
    vector<bool> isCheckedVec(inputNum + 1, false);
    bFSVec.push(inputNum);
    cout << BFS(graphVec, bFSVec, isCheckedVec, 0);
}
