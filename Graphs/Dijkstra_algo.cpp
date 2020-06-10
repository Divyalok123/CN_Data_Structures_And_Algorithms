// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
// Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
// Print the ith vertex number and the distance from source in one line separated by space. Print different vertices in different lines.
// Note : Order of vertices in output doesn't matter.

#include <iostream>
#include <climits>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 1e7

int findmin(int *distance, bool *visited, int v)
{
    int ourmin = -1;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i] && (ourmin == -1 || distance[i] < distance[ourmin]))
        {
            ourmin = i;
        }
    }

    return ourmin;
}

void dijkstra(int **edges, int v)
{
    bool *visited = new bool[v];
    int *distance = new int[v];
    for (int i = 0; i < v; i++)
    {
        distance[i] = MAX;
        visited[i] = false;
    }
    distance[0] = 0;

    for (int i = 0; i < v - 1; i++)
    {
        int mindist = findmin(distance, visited, v);
        visited[mindist] = true;
        for (int i = 0; i < v; i++)
        {
            if (edges[mindist][i] && !visited[i])
            {
                int tempdist = distance[mindist] + edges[mindist][i];
                if (tempdist < distance[i])
                {
                    distance[i] = tempdist;
                }
            }
        }
    }

    for (int i = 0; i < v; i++)
    {
        cout << i << ' ' << distance[i] << endl;
    }

    delete[] visited;
    delete[] distance;
}

int main()
{
    int V, E;
    cin >> V >> E;

    int **graph = new int *[V];
    for (int i = 0; i < V; i++)
    {
        graph[i] = new int[V];
        for (int j = 0; j < V; j++)
        {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < E; i++)
    {
        int vs, vd, w;
        cin >> vs >> vd >> w;
        graph[vs][vd] = w;
        graph[vd][vs] = w;
    }

    dijkstra(graph, V);

    for (int i = 0; i < V; i++)
    {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}
