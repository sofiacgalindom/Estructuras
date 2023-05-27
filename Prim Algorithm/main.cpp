#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

#define INF INT_MAX

void printMST(vector<int> parent, vector<vector<int>> graph) {
    int vertices = parent.size();
    cout << "Edge   Weight\n";
    for (int i = 1; i < vertices; i++)
        cout << parent[i] << " - " << i << "    " << graph[i][parent[i]] << endl;
}

void primMST(vector<vector<int>> graph) {
    int vertices = graph.size();
    vector<int> parent(vertices); 
    vector<int> key(vertices, INF); 
    bool mstSet[vertices]; 

    key[0] = 0; 
    parent[0] = -1;

    for (int count = 0; count < vertices - 1; count++) {
        int u = -1;
        
        for(int i=0;i<vertices;i++)
            if (!mstSet[i] && (u == -1 || key[i] < key[u]))
                u = i;
                
        mstSet[u] = true;

        for (int v = 0; v < vertices; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent, graph);
}

int main() {
    vector<vector<int>> graph = { {0, 2, 0, 6, 0},
                                  {2, 0, 3, 8, 5},
                                  {0, 3, 0, 0, 7},
                                  {6, 8, 0, 0, 9},
                                  {0, 5, 7, 9, 0}};
                                  
    primMST(graph);
    return 0;
}
