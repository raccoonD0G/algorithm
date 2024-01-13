#include <iostream>
#include <vector>
#define MAX_INPUT 12
using namespace std;

int GetAnswer(int inputNum, vector<int>& answerVec)
{
    return answerVec[inputNum];
}

int main()
{
    int numOfCase = 0;
    cin >> numOfCase;
    
    vector<int> caseVec(numOfCase);
    
    vector<int> answerVec(MAX_INPUT, 0);
    
    answerVec[0] = 0;
    answerVec[1] = 1;
    answerVec[2] = 2;
    answerVec[3] = 4;
    
    for (int i = 4; i < MAX_INPUT; i++)
    {
        answerVec[i] = answerVec[i - 1] + answerVec[i - 2] + answerVec[i - 3];
    }
    
    for (int i = 0; i < numOfCase; i++)
    {
        cin >> caseVec[i];
    }
    
    for (int i = 0; i < numOfCase; i++)
    {
        cout << GetAnswer(caseVec[i], answerVec) << "\n";
    }

    return 0;
}