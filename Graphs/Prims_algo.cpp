// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
// Find and print the Minimum Spanning Tree (MST) using Prim's algorithm.
// For printing MST follow the steps -
// 1. In one line, print an edge which is part of MST in the format -
// v1 v2 w
// where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1 <= v2 i.e. print the smaller vertex first while printing an edge.
// 2. Print V-1 edges in above format in different lines.
// Note : Order of different edges doesn't matter.

#include <iostream>
#include <climits>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 1e7

//this is a O(V^2) solution which is not good
//and can be better if we use a min heap with map
//to achive O((E+V)logV)

int findmin(int *weight, bool *visited, int v)
{
    int minVert = -1;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i] && (minVert == -1 || weight[i] < weight[minVert]))
        {
            minVert = i;
        }
    }

    return minVert;
}

void primsAlgo(int **edges, int v)
{
    bool *visited = new bool[v];

    int *parent = new int[v];
    parent[0] = -1;

    int *weight = new int[v];
    weight[0] = 0;

    for (int i = 1; i < v; i++)
    {
        weight[i] = MAX;
        visited[i] = false;
    }

    for (int i = 0; i < v - 1; i++)
    {
        int minVert = findmin(weight, visited, v);
        visited[minVert] = true;
        for (int j = 0; j < v; j++)
        {
            if (edges[minVert][j] && !visited[j])
            {
                if (edges[minVert][j] < weight[j])
                {
                    weight[j] = edges[minVert][j];
                    parent[j] = minVert;
                }
            }
        }
    }

    for (int i = 1; i < v; i++)
    {
        int v1 = i;
        int v2 = parent[i];
        if (v2 > v1)
        {
            cout << v1 << ' ' << v2 << ' ' << weight[i];
        }
        else
        {
            cout << v2 << ' ' << v2 << ' ' << weight[i];
        }
    }

    delete[] weight;
    delete[] parent;
    delete[] visited;
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

    primsAlgo(graph, V);

    for (int i = 0; i < V; i++)
    {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}
