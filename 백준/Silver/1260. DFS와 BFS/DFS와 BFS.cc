/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define SIZE 5
using namespace std;

void DFS(vector<vector<int>>& graphVec, int startNum, vector<bool>& isChecked)
{
    cout << startNum + 1 << " ";
    isChecked[startNum] = true;
    for(int i = 0; i < graphVec[startNum].size(); i++)
    {
        if(isChecked[graphVec[startNum][i]] == false)
        {
            DFS(graphVec, graphVec[startNum][i], isChecked);
        }
    }
    
    return;
}


void BFS(vector<vector<int>>& graphVec, int startNum, vector<bool> isChecked)
{
    queue<int> bFSQueue;
    cout << startNum + 1  << " ";
    isChecked[startNum] = true;
    bFSQueue.push(startNum);
    while (bFSQueue.empty() != true)
    {
        int queueSize = bFSQueue.size();
        for(int i = 0; i < queueSize; i++)
        {
            for(int j = 0; j < graphVec[bFSQueue.front()].size(); j++)
            {
                if (isChecked[graphVec[bFSQueue.front()][j]] == false)
                {
                    cout << graphVec[bFSQueue.front()][j] + 1 << " ";
                    bFSQueue.push(graphVec[bFSQueue.front()][j]);
                    isChecked[graphVec[bFSQueue.front()][j]] = true;
                }
            }
            bFSQueue.pop();
        }
    }
    return;
}

int main()
{
    int nodeNum, edgeNum, startNum = 0;
    cin >> nodeNum >> edgeNum >> startNum;
    
    vector<vector<int>> graphVec(nodeNum);
    vector<bool> isChecked(nodeNum, false);
    
    for (int i = 0; i < edgeNum; i++)
    {
        int start, end = 0;
        cin >> start >> end;
        graphVec[start - 1].push_back(end - 1);
        graphVec[end - 1].push_back(start - 1);
    }
    
    for (int i = 0; i < nodeNum; i++)
    {
        sort(graphVec[i].begin(), graphVec[i].end());
    }
    
    DFS(graphVec, startNum - 1, isChecked);
    cout << "\n";
    for (int i = 0; i < isChecked.size(); i++)
    {
        isChecked[i] = false;
    }
    BFS(graphVec, startNum - 1, isChecked);
    
    return 0;
}