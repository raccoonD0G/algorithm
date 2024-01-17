#include <iostream>
#include <vector>
#include <algorithm>

class Edge
{
public:
    int destination;
    int distance;
};

using namespace std;

int DFS(vector<vector<Edge>>& graphVec, vector<bool>& isChecked, int start, int& endNode)
{
    isChecked[start] = true;
    vector<int> lengthVec;
    vector<int> endNodeVec;
    for (int i = 0; i < graphVec[start].size(); i++)
    {
        Edge targetEdge = graphVec[start][i];
        if (isChecked[targetEdge.destination] == false)
        {
            int endNodeTmp = -1;
            lengthVec.push_back(DFS(graphVec, isChecked, targetEdge.destination, endNodeTmp) + targetEdge.distance);
            endNodeVec.push_back(endNodeTmp);
        }
    }
    
    if (lengthVec.size() == 0)
    {
        endNode = start;
        return 0;
    }
    else
    {
        int index = max_element(lengthVec.begin(), lengthVec.end()) - lengthVec.begin();
        endNode = endNodeVec[index];
        return lengthVec[index];
    }
    
}

int main()
{
    int numOfNode = 0;
    
    cin >> numOfNode;
    
    vector<vector<Edge>> graphVec(numOfNode);
    
    for (int i = 0; i < numOfNode; i++)
    {
        int start = 0;
        cin >> start;
        while(true)
        {
            int destination = 0;
            cin >> destination;
            
            if(destination != -1)
            {
                Edge edgeTmp;
                
                destination--;
                edgeTmp.destination = destination;
                
                cin >> edgeTmp.distance;
                
                graphVec[start - 1].push_back(edgeTmp);
            }
            else break;
        }
        
    }
    
    int endNode = -1;
    vector<bool> isChecked(numOfNode, false);
    
    DFS(graphVec, isChecked, 0, endNode);
    
    for (int i = 0; i < numOfNode; i++) isChecked[i] = false;
    
    int trash = -1;
    cout << DFS(graphVec, isChecked, endNode, trash);
    
    return 0;
}
