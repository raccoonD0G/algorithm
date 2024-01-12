/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Compare
{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};


int main()
{
    priority_queue<int, vector<int>, Compare> minHeap;
    
    int numOfCommand = 0;
    cin >> numOfCommand;
    
    vector<int> commandVec(numOfCommand);
    
    for (int i = 0; i < numOfCommand; i++)
    {
        cin >> commandVec[i];
    }
    
    for (int i = 0; i < numOfCommand; i++)
    {
        if (commandVec[i] == 0)
        {
            if (minHeap.empty() == true)
            {
                cout << 0 << "\n";
            }
            else
            {
                cout << minHeap.top() << "\n";
                minHeap.pop();
            }
        }
        else
        {
            minHeap.push(commandVec[i]);
        }
    }
    return 0;
}