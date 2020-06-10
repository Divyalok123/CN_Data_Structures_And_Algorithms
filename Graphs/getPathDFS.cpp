// Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
// Find the path using DFS and print the first path that you encountered.
// V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
// E is the number of edges present in graph G.
// Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.

#include <iostream>
#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> printPath(int ** edges, int V, int x, int y, bool* visited)
{
    if(x == y)
    {
        vector<int> temp;
        temp.push_back(x);
        return temp;
    }
    
    visited[x] = true;
    
    for(int i = 0; i < V; i++)
    {
        if(edges[x][i] && !visited[i])
        {
            vector<int> temp2 = printPath(edges, V, i, y, visited);
            if(temp2.size() > 0)
            {
                temp2.push_back(x);
                return temp2;
            }
        }
    }
    
    vector<int> fin;
    return fin;
}

int main()
{
      int V, E, tempX, tempY;
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
    
    bool* visited = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
	}
    
    cin >> tempX >> tempY;
    
    vector<int> result = printPath(matrix, V, tempX, tempY, visited);
    
    
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    
    delete[] visited;
    for(int i = 0; i < V; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
	return 0;
}
