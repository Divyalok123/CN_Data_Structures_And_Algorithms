// Given a graph with N vertices (numbered from 1 to N) and Two Lists (U,V) of size M where (U[i],V[i]) and (V[i],U[i]) are connected by an edge , then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected an edge.

#include <iostream>
#include <vector>
using namespace std;

int solve(int n, int m, vector<int> u, vector<int> v)
{
    int count = 0;

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
        int f = u[i] - 1;
        int s = v[i] - 1;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (edges[i][j] && j != i)
            {
                for (int k = 0; k < n; k++)
                {
                    if (edges[j][k] && k != i && k != j)
                    {
                        if (edges[i][k])
                            count++;
                    }
                }
            }
        }
    }

    return count / 6;
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