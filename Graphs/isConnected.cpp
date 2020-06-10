// Given an undirected graph G(V,E), check if the graph G is connected graph or not.
// V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
// E is the number of edges present in graph G.

#include <iostream>
#include <climits>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

void DFS(int **edges, int v, int s, bool *visited)
{
    visited[s] = true;
    // cout << "Checkpoint 5" << endl;

    for (int i = 0; i < v; i++)
    {
        if (edges[s][i] && !visited[i])
        {
            DFS(edges, v, i, visited);
            // cout << "Checkpoint 6"
            //      << " ";
        }
    }
}

int main()
{

    int V, E;
    cin >> V >> E;

    int **edges = new int *[V];
    for (int i = 0; i < V; i++)
    {
        edges[i] = new int[V];
        for (int j = 0; j < V; j++)
        {
            edges[i][j] = 0;
        }
    }

    // cout << "Checkpoint 1" << endl;

    for (int i = 0; i < E; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    // cout << "Checkpoint 2" << endl;

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    // cout << "Checkpoint 3" << endl;

    DFS(edges, V, 0, visited);

    // cout << "Checkpoint 4" << endl;

    for (int i = 0; i < V; i++)
    {
        // cout << "Checkpoint 7"
        //      << " ";
        if (!visited[i])
        {
            cout << endl;
            cout << "false";
            return 0;
            // return;
        }
    }

    cout << "true";
    return 0;
}
