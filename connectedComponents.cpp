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
