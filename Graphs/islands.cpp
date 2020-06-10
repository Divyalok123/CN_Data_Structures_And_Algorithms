// An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given N islands (numbered from 1 to N) and two lists of size M (u and v) denoting island u[i] is connected to island v[i] and vice versa . Can you count the number of connected groups of islands.

#include <iostream>
#include <vector>
using namespace std;

void DFS(int **edges, int v, int s, bool *visited)
{
    visited[s] = true;
    for (int i = 0; i < v; i++)
    {
        if (edges[s][i] && !visited[i])
        {
            DFS(edges, v, i, visited);
        }
    }
}

int counter(int **edges, int v)
{
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    int count = 0;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            count++;
            DFS(edges, v, i, visited);
        }
    }

    delete[] visited;
    return count;
}

int solve(int n, int m, vector<int> u, vector<int> v)
{
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int f = u.at(i) - 1;
        int s = v.at(i) - 1;

        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    int ans = counter(edges, n);

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;

    return ans;
}

int main()
{
    int n, m;
    vector<int> u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        u.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << solve(n, m, u, v) << endl;
}