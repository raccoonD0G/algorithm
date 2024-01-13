#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int BFS(vector<vector<int>>& graphVec, vector<bool>& isCheckedVec)
{
    int count = 0;
    queue<int> bFSQueue;
    bFSQueue.push(0);
    while (bFSQueue.empty() == false)
    {
        int queueSize = bFSQueue.size();
        for (int i = 0; i < queueSize; i++)
        {
            for(int j = 0; j < graphVec[bFSQueue.front()].size(); j++)
            {
                if (isCheckedVec[graphVec[bFSQueue.front()][j]] == false)
                {
                    bFSQueue.push(graphVec[bFSQueue.front()][j]);
                    isCheckedVec[graphVec[bFSQueue.front()][j]] =  true;
                    count++;
                }
            }
            bFSQueue.pop();
        }
    }
    
    return count;
}

int main()
{
    int numOfNode, numOfEdge = 0;
    
    cin >> numOfNode >> numOfEdge;
    
    vector<vector<int>> graphVec(numOfNode);
    
    for (int i = 0; i < numOfEdge; i++)
    {
        int start, end = 0;
        cin >> start >> end;
        
        graphVec[start - 1].push_back(end - 1);
        graphVec[end - 1].push_back(start - 1);
    }
    
    vector<bool> isCheckedVec(numOfNode, false);
    isCheckedVec[0] = true;
    
    cout << BFS(graphVec, isCheckedVec);
}