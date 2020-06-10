// Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), check if there exists any path between them or not. Print true or false.
// V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
// E is the number of edges present in graph G.

#include <iostream>
using namespace std;

bool hasPath(int **edges, int V, int v1, int v2, bool *visited)
{
    if (edges[v1][v2] || v1 == v2)
    {
        return true;
    }

    visited[v1] = true;
    for (int i = 0; i < V; i++)
    {
        if (edges[v1][i])
        {
            if (!visited[i])
            {
                if (hasPath(edges, V, i, v2, visited))
                    return true;
            }
        }
    }

    return false;
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

    int v1, v2;
    cin >> v1 >> v2;

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    bool hasP = hasPath(matrix, V, v1, v2, visited);

    if (hasP)
    {
        cout << "true" << endl;
    }
    else
        cout << "false" << endl;

    return 0;
}
