#include <iostream>
#include <vector>
#include <queue>
#define MAX_START_POS 100000
using namespace std;

int BFS(vector<vector<int>>& graphVec, queue<int>& bFSQueue, int hider)
{
    if (bFSQueue.front() == hider) return 0;
    vector<bool> isChecked(2 * MAX_START_POS + 1, false);

    int count = 0;
    while (bFSQueue.empty() == false)
    {
        int bFSQueueSize = bFSQueue.size();
        for (int i = 0; i < bFSQueueSize; i++)
        {
            for (int j = 0; j < graphVec[bFSQueue.front()].size(); j++)
            {
                if (isChecked[graphVec[bFSQueue.front()][j]] == false)
                {
                    if (graphVec[bFSQueue.front()][j] == hider) return ++count;
                    bFSQueue.push(graphVec[bFSQueue.front()][j]);
                    isChecked[graphVec[bFSQueue.front()][j]] = true;
                }
            }
            bFSQueue.pop();
        }
        count++;
    }
    return 0;
}

int main()
{
    int finder = 0;
    int hider = 0;

    cin >> finder >> hider;

    vector<vector<int>> graphVec(2 * MAX_START_POS + 1);

    for (int i = 0; i < 2 * MAX_START_POS + 1; i++)
    {
        if (i - 1 <= 2 * MAX_START_POS && i - 1 >= 0) graphVec[i].push_back(i - 1);
        if (i + 1 <= 2 * MAX_START_POS && i + 1 >= 0) graphVec[i].push_back(i + 1);
        if (i * 2 <= 2 * MAX_START_POS && 2 * i >= 0) graphVec[i].push_back(2 * i);
    }

    queue<int> bFSQueue;

    bFSQueue.push(finder);

    cout << BFS(graphVec, bFSQueue, hider);

}