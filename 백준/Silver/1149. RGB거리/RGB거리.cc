#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void SetCost(vector<vector<int>>& costVec, int index)
{
    costVec[index][0] += min(costVec[index - 1][1], costVec[index - 1][2]);
    costVec[index][1] += min(costVec[index - 1][0], costVec[index - 1][2]);
    costVec[index][2] += min(costVec[index - 1][0], costVec[index - 1][1]);
    return;
}

int main()
{
    int numOfHouse = 0;
    cin >> numOfHouse;
    
    vector<vector<int>> costVec(numOfHouse);
    
    for (int i = 0; i < numOfHouse; i++)
    {
        costVec[i].resize(3);
        cin >> costVec[i][0];
        cin >> costVec[i][1];
        cin >> costVec[i][2];
    }
    
    for (int i = 1; i < numOfHouse; i++)
    {
        SetCost(costVec, i);
    }
    
    cout << *min_element(costVec[numOfHouse - 1].begin(), costVec[numOfHouse - 1].end());
    return 0;
}