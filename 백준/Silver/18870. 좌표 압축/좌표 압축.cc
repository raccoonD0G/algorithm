#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int coordinationNum;
    cin >> coordinationNum;
    
    vector<int> coordinationVec(coordinationNum);
    vector<int> answerVec(coordinationNum);
    for (int i = 0; i < coordinationNum; i++)
    {
        cin >> coordinationVec[i];
    }
    
    vector<int> sortedCoord(coordinationVec);
    sort(sortedCoord.begin(), sortedCoord.end());
    sortedCoord.erase(unique(sortedCoord.begin(), sortedCoord.end()), sortedCoord.end());
    
    for (int i = 0; i < coordinationNum; i++)
    {
        cout << lower_bound(sortedCoord.begin(), sortedCoord.end(), coordinationVec[i]) - sortedCoord.begin() << " ";
    }
}