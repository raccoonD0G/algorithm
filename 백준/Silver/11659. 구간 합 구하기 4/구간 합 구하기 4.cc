#include <iostream>
#include <vector>
#include <map>

using namespace std;

int GetAnswer(int start, int end, vector<int>& sumVec)
{
    return sumVec[end] - sumVec[start - 1];
}

int main()
{
    int vecLength, numOfCase = 0;
    
    cin >> vecLength >> numOfCase;
    
    vector<int> numVec(vecLength);
    
    for (int i = 0; i < vecLength; i++)
    {
        cin >> numVec[i];
    }
    
    vector<int> sumVec(vecLength, 0);
    sumVec[0] = numVec[0];
    
    for (int i = 1; i < vecLength; i++)
    {
        sumVec[i] = sumVec[i - 1] + numVec[i];
    }
    
    
    vector<vector<int>> caseVec(numOfCase);
    
    for (int i = 0; i < numOfCase; i++)
    {
        vector<int> tmp(2);
        cin >> tmp[0] >> tmp[1];
        tmp[0]--;
        tmp[1]--;
        caseVec[i] = tmp;
    }
    
    for (int i = 0; i < numOfCase; i++)
    {
        cout << GetAnswer(caseVec[i][0], caseVec[i][1], sumVec) << "\n";
    }
    
}