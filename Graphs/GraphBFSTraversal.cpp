#include <iostream>
#include <climits>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

void print(int **matrix, int v, int s, bool *visited)
{
    queue<int> q;

    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int start = q.front();
        q.pop();
        cout << start << " ";

        for (int i = 0; i < v; i++)
        {
            if (i == start)
                continue;
            if (matrix[start][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS(int **edges, int v)
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

    BFS(matrix, V);

    for (int i = 0; i < V; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}
