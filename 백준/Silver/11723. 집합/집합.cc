#include <iostream>
#include <vector>
#include <string>
#define MAX_SIZE 20

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int setInt = 0;
    
    int cmdNum = 0;
    cin >> cmdNum;
    
    for (int i = 0; i < cmdNum; i++)
    {
        string cmdTmp;
        cin >> cmdTmp;
        int numTmp = 0;
        if (cmdTmp == "add")
        {
            cin >> numTmp;
            setInt = setInt | (1 << numTmp - 1);
        }
        else if (cmdTmp == "remove")
        {
            cin >> numTmp;
            setInt = setInt & ~(1 << numTmp - 1);
        }
        else if (cmdTmp == "check")
        {
            cin >> numTmp;
            if ((setInt & (1 << numTmp - 1)) > 0) cout << 1;
            else cout << 0;
            cout << "\n";
        }
        else if (cmdTmp == "toggle")
        {
            cin >> numTmp;
            setInt = setInt ^ (1 << numTmp - 1);
        }
        else if (cmdTmp == "all")
        {
            setInt = (~0);
        }
        else if (cmdTmp == "empty")
        {
            setInt = 0;
        }
    }
    
    return 0;
}