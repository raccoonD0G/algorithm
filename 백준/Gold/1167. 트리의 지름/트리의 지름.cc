#include <iostream>
#include <vector>
using namespace std;

class Edge {
public:
    int destination;
    int distance;
};

int maxDistance = 0;
int farthestNode = 0;

void DFS(vector<vector<Edge>>& graphVec, vector<bool>& isChecked, int start, int length) {
    isChecked[start] = true;

    if (length > maxDistance) {
        maxDistance = length;
        farthestNode = start;
    }

    for (Edge& edge : graphVec[start]) {
        if (!isChecked[edge.destination]) {
            DFS(graphVec, isChecked, edge.destination, length + edge.distance);
        }
    }
}

int main() {
    int numOfNode;
    cin >> numOfNode;

    vector<vector<Edge>> graphVec(numOfNode + 1);

    for (int i = 0; i < numOfNode; i++) {
        int node;
        cin >> node;
        while (true) {
            int destination, distance;
            cin >> destination;
            if (destination == -1) {
                break;
            }
            cin >> distance;

            graphVec[node].push_back(Edge{destination, distance});
        }
    }

    // 첫 번째 DFS 실행
    vector<bool> isChecked(numOfNode + 1, false);
    DFS(graphVec, isChecked, 1, 0);

    // 두 번째 DFS 실행
    fill(isChecked.begin(), isChecked.end(), false);
    maxDistance = 0;
    DFS(graphVec, isChecked, farthestNode, 0);

    cout << maxDistance;

    return 0;
}
