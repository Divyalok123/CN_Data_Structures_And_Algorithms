#include <iostream>
#include <climits>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

void print(int **edges, int v, int s, bool *visited)
{
    cout << s << " ";
    visited[s] = true;
    for (int i = 0; i < v; i++)
    {
        if (i == s)
            continue;
        if (edges[s][i] && !visited[i])
        {
            print(edges, v, i, visited);
        }
    }
}

void DFS(int **edges, int v)
{
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            print(edges, v, i, visited);
        }
    }
    delete[] visited;
}

int main()
{
    int V, E;
    cin >> V >> E;

    int **matrix = new int *[V];
    for (int i = 0; i < V; i++)
    {
        matrix[i] = new int[V];
        for (int j = 0; j < V; j++)
        {
            matrix[i][j] = 0;
        }
    }

    for (int j = 0; j < E; j++)
    {
        int f, s;
        cin >> f >> s;
        matrix[f][s] = 1;
        matrix[s][f] = 1;
    }

    DFS(matrix, V);

    for (int i = 0; i < V; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
