// Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
// Find the path using BFS and print the shortest path available.
// V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
// E is the number of edges present in graph G.
// Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> path(int **matrix, int v, int v1, int v2,  bool * visited)
{
    queue<int> q;
    vector<int> output;
    unordered_map<int, int> mymap;

    q.push(v1);
    visited[v1] = true;

    while (!q.empty())
    {
        int start = q.front();
        q.pop();
        int i;
        for (i = 0; i < v; i++)
        {
            if (i == start)
                continue;
            if (matrix[start][i] == 1 && !visited[i])
            {
                q.push(i);
                mymap[i] = start;
                visited[i] = true;
                if(i == v2)
                {
                    output.push_back(i);
                    break;
                }
            }
        }
        
        if(i == v2)
        {
            break;
        }
    }
    
	while(mymap.find(v2) != mymap.end())
	{
        v2 = mymap.at(v2);
        output.push_back(v2);
	}
    
    return output;   
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
	
    vector<int> res = path(matrix, V, tempX, tempY, visited);
	
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
        
    delete[] visited;
    for(int i = 0; i < V; i++)
    {
        delete [] matrix[i];
    }
    delete [] matrix;

    return 0;
}
