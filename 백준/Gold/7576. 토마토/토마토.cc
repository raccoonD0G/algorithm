#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Box
{
public:
    bool isTomato;
    bool isRipen;
    bool isChecked;
};

bool IsAllRippen(vector<vector<Box>>& boxTableVec)
{
    for (int i = 0; i < boxTableVec.size(); i++)
    {
        for (int j = 0; j < boxTableVec[i].size(); j++)
        {
            if (boxTableVec[i][j].isTomato == true && boxTableVec[i][j].isRipen == false)
            return false;
        }
    }
    return true;
}

bool CheckAndChangeTomato(vector<vector<Box>>& boxTableVec, int i, int j, queue<vector<int>>& ripenToday)
{
    if (i >= 0 && i < boxTableVec.size() && j >= 0 && j < boxTableVec[i].size())
    {
        if (boxTableVec[i][j].isTomato == true && boxTableVec[i][j].isRipen == false)
        {
            vector<int> tmp(2);
            tmp[0] = i;
            tmp[1] = j;
            boxTableVec[i][j].isRipen = true;
            ripenToday.push(tmp);
            return true;
        }
    }
    return false;
}

int BFS(vector<vector<Box>>& boxTableVec)
{
    int dayCount = 0;
    queue<vector<int>> ripenToday;
    
    for (int i = 0; i < boxTableVec.size(); i++)
    {
        for (int j = 0; j < boxTableVec[i].size(); j++)
        {
            vector<int> tmp(2);
            if (boxTableVec[i][j].isTomato == true && boxTableVec[i][j].isRipen == true)
            {
                tmp[0] = i;
                tmp[1] = j;
                ripenToday.push(tmp);
            }
        }
    }
    
    bool isChange = true;
    while (isChange == true)
    {
        isChange = false;
        int ripenTodaySize = ripenToday.size();
        for (int i = 0; i < ripenTodaySize; i++)
        {
            
            boxTableVec[ripenToday.front()[0]][ripenToday.front()[1]].isChecked = false;
            
            bool isChange0 = CheckAndChangeTomato(boxTableVec, ripenToday.front()[0] - 1, ripenToday.front()[1], ripenToday);
            bool isChange1 = CheckAndChangeTomato(boxTableVec, ripenToday.front()[0] + 1, ripenToday.front()[1], ripenToday);
            bool isChange2 = CheckAndChangeTomato(boxTableVec, ripenToday.front()[0], ripenToday.front()[1] - 1, ripenToday);
            bool isChange3 = CheckAndChangeTomato(boxTableVec, ripenToday.front()[0], ripenToday.front()[1] + 1, ripenToday);
            isChange = isChange || isChange0 || isChange1 || isChange2 || isChange3;
            ripenToday.pop();
        }
        
        if (isChange == true) dayCount++;
    }
    return dayCount;
}

int main()
{
    int row, column = 0;
    cin >> row >> column;
    
    vector<vector<Box>> boxTableVec(row);
    
    for (int i = 0; i < row; i++)
    {
        boxTableVec[i].resize(column);
    }
    
    for (int i = 0; i < column; i++)
    {
        for (int j = 0; j < row; j++)
        {
            int tmp = 0;
            cin >> tmp;
            if (tmp == 0)
            {
                boxTableVec[j][i].isTomato = true;
                boxTableVec[j][i].isRipen = false;
                boxTableVec[j][i].isChecked = false;
            }
            else if (tmp == 1)
            {
                boxTableVec[j][i].isTomato = true;
                boxTableVec[j][i].isRipen = true;
                boxTableVec[j][i].isChecked = true;
            }
            else if (tmp == -1)
            {
                boxTableVec[j][i].isTomato = false;
                boxTableVec[j][i].isRipen = false;
                boxTableVec[j][i].isChecked = false;
            }
            
        }
        
    }
    int anwer = BFS(boxTableVec);
    
    if (IsAllRippen(boxTableVec) == false) cout << "-1";
    else cout << anwer;
}