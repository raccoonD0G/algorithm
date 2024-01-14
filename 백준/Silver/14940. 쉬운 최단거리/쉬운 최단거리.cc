#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void SetMin(vector<vector<int>>& ground, vector<vector<int>>& answer, int i, int j)
{
    if (ground[i][j] == 0) return;

    vector<int> tmpVec;
    if (i - 1 >= 0 && i - 1 < ground.size() && answer[i - 1][j] > -1)
    {
        tmpVec.push_back(answer[i - 1][j]);
    }
    if (i + 1 >= 0 && i + 1 < ground.size() && answer[i + 1][j] > -1)
    {
        tmpVec.push_back(answer[i + 1][j]);
    }
    if (j - 1 >= 0 && j - 1 < ground[0].size() && answer[i][j - 1] > -1)
    {
        tmpVec.push_back(answer[i][j - 1]);
    }
    if (j + 1 >= 0 && j + 1 < ground[0].size() && answer[i][j + 1] > -1)
    {
        tmpVec.push_back(answer[i][j + 1]);
    }

    if (tmpVec.empty() == false) answer[i][j] = 1 + *min_element(tmpVec.begin(), tmpVec.end());
    return;
}

void BFS(vector<vector<int>>& ground, vector<vector<int>>& answer, int startRow, int startColumn, vector<vector<bool>>& isCheckedVec)
{
    queue<vector<int>> bFSQueue;
    vector<int> start(2);

    start[0] = startRow;
    start[1] = startColumn;
    bFSQueue.push(start);
    isCheckedVec[start[0]][start[1]] = true;

    while (bFSQueue.empty() == false)
    {
        int queueSIze = bFSQueue.size();
        for (int i = 0; i < queueSIze; i++)
        {
            vector<int> tmpVec(bFSQueue.front());
            SetMin(ground, answer, bFSQueue.front()[0], bFSQueue.front()[1]);
            if (bFSQueue.front()[0] - 1 >= 0 && answer[bFSQueue.front()[0] - 1][bFSQueue.front()[1]] == -1)
            {
                tmpVec[0] = bFSQueue.front()[0] - 1;
                tmpVec[1] = bFSQueue.front()[1];
                if (isCheckedVec[tmpVec[0]][tmpVec[1]] == false && ground[tmpVec[0]][tmpVec[1]] != 0)
                {
                    bFSQueue.push(tmpVec);
                    isCheckedVec[tmpVec[0]][tmpVec[1]] = true;
                }
            }
            if (bFSQueue.front()[0] + 1 < ground.size() && answer[bFSQueue.front()[0] + 1][bFSQueue.front()[1]] == -1)
            {
                tmpVec[0] = bFSQueue.front()[0] + 1;
                tmpVec[1] = bFSQueue.front()[1];
                if (isCheckedVec[tmpVec[0]][tmpVec[1]] == false && ground[tmpVec[0]][tmpVec[1]] != 0)
                {
                    bFSQueue.push(tmpVec);
                    isCheckedVec[tmpVec[0]][tmpVec[1]] = true;
                }
            }
            if (bFSQueue.front()[1] - 1 >= 0 && answer[bFSQueue.front()[0]][bFSQueue.front()[1] - 1] == -1)
            {
                tmpVec[0] = bFSQueue.front()[0];
                tmpVec[1] = bFSQueue.front()[1] - 1;
                if (isCheckedVec[tmpVec[0]][tmpVec[1]] == false && ground[tmpVec[0]][tmpVec[1]] != 0)
                {
                    bFSQueue.push(tmpVec);
                    isCheckedVec[tmpVec[0]][tmpVec[1]] = true;
                }
            }
            if (bFSQueue.front()[1] + 1 < ground[0].size() && answer[bFSQueue.front()[0]][bFSQueue.front()[1] + 1] == -1)
            {
                tmpVec[0] = bFSQueue.front()[0];
                tmpVec[1] = bFSQueue.front()[1] + 1;
                if (isCheckedVec[tmpVec[0]][tmpVec[1]] == false && ground[tmpVec[0]][tmpVec[1]] != 0)
                {
                    bFSQueue.push(tmpVec);
                    isCheckedVec[tmpVec[0]][tmpVec[1]] = true;
                }
            }
            bFSQueue.pop();
        }
    }
    return;
}

int main()
{
    int row, column = 0;
    cin >> row >> column;

    int startPoint[2] = { 0, 0 };
    vector<vector<int>> ground(row);
    vector<vector<int>> answer(row);

    for (int i = 0; i < row; i++)
    {
        ground[i].resize(column);
        answer[i].resize(column);
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            cin >> ground[i][j];
            if (ground[i][j] == 2)
            {
                answer[i][j] = 0;
                startPoint[0] = i;
                startPoint[1] = j;
            }
            else answer[i][j] = -1;
        }
    }

    vector<vector<bool>> isCheckedVec(row);
    for (int i = 0; i < row; i++)
    {
        isCheckedVec[i].resize(column, false);
    }

    BFS(ground, answer, startPoint[0], startPoint[1], isCheckedVec);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (ground[i][j] == 0) cout << "0" << " ";
            else cout << answer[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}