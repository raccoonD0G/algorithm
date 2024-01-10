#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int DFS(vector<vector<int>>& graphVec, queue<int>& dFSVec, vector<bool>& isCheckedVec, int count)
{
    int dFSVecLength = 0;
    while (dFSVec.empty() == false)
    {
        dFSVecLength = dFSVec.size();
        for (int i = 0; i < dFSVecLength; i++)
        {
            for (int j = 0; j < graphVec[dFSVec.front()].size(); j++)
            {
                int tmp = graphVec[dFSVec.front()][j];
                if (tmp == 1) return ++count;
                else
                {
                    if (isCheckedVec[tmp] == false)
                    {
                        isCheckedVec[tmp] = true;
                        dFSVec.push(tmp);
                    }
                }
            }
            dFSVec.pop();
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

    queue<int> dFSVec;
    vector<bool> isCheckedVec(inputNum + 1, false);
    dFSVec.push(inputNum);
    cout << DFS(graphVec, dFSVec, isCheckedVec, 0);
}
