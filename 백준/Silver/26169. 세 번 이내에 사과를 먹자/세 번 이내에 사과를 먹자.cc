/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 5
using namespace std;

class Box
{
public:
    int r;
    int c;
    bool isApple;
    bool isChecked;
};

int DFS(vector<vector<Box>> boxMap, int r, int c, int chance)
{
    if (r < 0 || r > 4) return 0;
    if (c < 0 || c > 4) return 0;
    if (chance == -1) return 0;
    if (boxMap[r][c].isChecked == true) return 0;
    
    boxMap[r][c].isChecked = true;
    chance--;
    
    vector<int> tryApple(4);
    
    tryApple[0] = DFS(boxMap, r - 1, c, chance);
    tryApple[1] = DFS(boxMap, r + 1, c, chance);
    tryApple[2] = DFS(boxMap, r, c - 1, chance);
    tryApple[3] = DFS(boxMap, r, c + 1, chance);
    
    if (boxMap[r][c].isApple == true) return (*max_element(tryApple.begin(), tryApple.end()) + 1);
    else return *max_element(tryApple.begin(), tryApple.end());
}

int main()
{
    vector<vector<Box>> myMap(SIZE);
    
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            int tmpInt;
            Box tmpBox;
            cin >> tmpInt;
            if (tmpInt == 0)
            {
                tmpBox.isApple = false;
                tmpBox.isChecked = false;
            }
            else if (tmpInt == 1)
            {
                tmpBox.isApple = true;
                tmpBox.isChecked = false;
            }
            else if (tmpInt == -1)
            {
                tmpBox.isApple = false;
                tmpBox.isChecked = true;
            }
            
            tmpBox.r = i;
            tmpBox.c = j;
            myMap[i].push_back(tmpBox);
        }
    }

    
    int r, c = 0;
    cin >> r >> c;
    
    if (DFS(myMap, r, c, 3) >= 2) cout << "1";
    else cout << "0";
    return 0;
}