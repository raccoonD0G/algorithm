#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int numOfPeople = 0;
    
    cin >> numOfPeople;
    
    vector<int> numVec(numOfPeople);
    
    for (int i = 0; i < numOfPeople; i++)
    {
        cin >> numVec[i];
    }
    
    sort(numVec.begin(), numVec.end());
    
    vector<int> sumVec(numVec);
    
    sumVec[0] = numVec[0];
    for (int i = 1; i < numOfPeople; i++)
    {
        sumVec[i] = sumVec[i - 1] + numVec[i];
    }
    
    int answer = 0;
    for (int i = 0; i < numOfPeople; i++)
    {
        answer += sumVec[i];
    }
    
    cout << answer;

    return 0;
}