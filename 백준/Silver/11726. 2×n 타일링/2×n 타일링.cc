#include <iostream>
#include <vector>
#define MAX_SIZE 1000
#define MOD_NUM 10007
using namespace std;

int main()
{
    int rectSize = 0;
    cin >> rectSize;
    
    vector<int> answerVec(MAX_SIZE + 1, 0);
    answerVec[1] = 1;
    answerVec[2] = 2;
    answerVec[3] = 3;
    
    for (int i = 4; i < MAX_SIZE + 1; i++)
    {
        answerVec[i] = (answerVec[i - 1] % MOD_NUM) + (answerVec[i - 2] % MOD_NUM) % MOD_NUM;
    }
    
    cout << answerVec[rectSize] % MOD_NUM;
    
    return 0;
}