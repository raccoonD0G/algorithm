#include <iostream>
#include <vector>

using namespace std;

class CabbageSpace;
int GetAnswer(int width, int height, CabbageSpace** farm);
void DoFertilize(int x, int y, int width, int height, CabbageSpace** farm);

class CabbageSpace
{
public :
    bool isCabbage;
    bool isFertilized;
};

int GetAnswer(int width, int height, CabbageSpace** farm)
{
    int connectedComponentCount = 0;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (farm[i][j].isCabbage == true && farm[i][j].isFertilized == false)
            {
                connectedComponentCount++;
                DoFertilize(i, j, width, height, farm);
            }
        }
    }
    return connectedComponentCount;
}

void DoFertilize(int x, int y, int width, int height, CabbageSpace** farm)
{
    if (farm[x][y].isCabbage == true && farm[x][y].isFertilized == false)
    {
        farm[x][y].isFertilized = true;
        if (x - 1 >= 0) DoFertilize(x - 1, y, width, height, farm);
        if (x + 1 < width) DoFertilize(x + 1, y, width, height, farm);
        if (y - 1 >= 0) DoFertilize(x, y - 1, width, height, farm);
        if (y + 1 < height) DoFertilize(x, y + 1, width, height, farm);
    }
    else return;
}

int main()
{
    int numberOfCase;
    cin >> numberOfCase;
    
    vector<int> answerVec(numberOfCase);
    
    for (int i = 0; i < numberOfCase; i++)
    {
        int width, height, numberOfCabbage;
        cin >> width >> height >> numberOfCabbage;
        
        CabbageSpace** farm;
        
        farm = new CabbageSpace*[width];
        
        for (int j = 0; j < width; j++)
        {
            farm[j] = new CabbageSpace[height];
            for (int k = 0; k < height; k++)
            {
                farm[j][k].isCabbage = false;
                farm[j][k].isFertilized = false;
            }
        }
        
        for (int j = 0; j < numberOfCabbage; j++)
        {
            int x, y;
            cin >> x >> y;
            farm[x][y].isCabbage = true;
        }
        
        answerVec[i] = GetAnswer(width, height, farm);
    }
    
    for (int i = 0; i < numberOfCase; i++)
    {
        cout << answerVec[i] << "\n";
    }
}