#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void DFS(vector<vector<int>>& graphVec, vector<bool>& isCheckedVec, int i)
{
    if (isCheckedVec[i] == false)
    {
        isCheckedVec[i] = true;
        for (int j = 0; j < graphVec[i].size(); j++)
        {
            DFS(graphVec, isCheckedVec, graphVec[i][j]);
        }
    }
    
    return;
}

int NumOFCC(vector<vector<int>>& graphVec, vector<bool>& isCheckedVec)
{
    int count = 0;
    for (int i = 0; i < graphVec.size(); i++)
    {
        if (isCheckedVec[i] == false)
        {
            count++;
            DFS(graphVec, isCheckedVec, i);
        }
    }
    return count;
}

int main()
{
    int nodeNum, edgeNum = 0;
    
    cin >> nodeNum >> edgeNum;
    
    vector<vector<int>> graphVec(nodeNum);
    
    for (int i = 0; i < edgeNum; i++)
    {
        int start, end = 0;
        cin >> start >> end;
        graphVec[start - 1].push_back(end - 1);
        graphVec[end - 1].push_back(start - 1);
    }
    
    vector<bool> isCheckedVec(nodeNum, false);
    
    cout << NumOFCC(graphVec, isCheckedVec);

    return 0;
}