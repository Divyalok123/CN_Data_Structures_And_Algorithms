// Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
// V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
// E is the number of edges present in graph G.
// You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
// Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.

#include <iostream>
#include <climits>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> helper(int **edges, int v, int s, bool *visited, vector<int> output)
{
    output.push_back(s);
    visited[s] = true;

    for (int i = 0; i < v; i++)
    {
        if (i == s)
            continue;
        if (edges[s][i] && !visited[i])
        {
            output = helper(edges, v, i, visited, output);
        }
    }
    sort(output.begin(), output.end());

    return output;
}

vector<vector<int>> DFS(int **edges, int v)
{
    vector<vector<int>> output;
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            vector<int> temp;
            temp = helper(edges, v, i, visited, temp);
            output.push_back(temp);
        }
    }
    delete[] visited;
    return output;
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

    for (int i = 0; i < E; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    vector<vector<int>> output;
    output = DFS(edges, V);

    for (int i = 0; i < output.size(); i++)
    {
        for (int j = 0; j < output[i].size(); j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < V; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}
