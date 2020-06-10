// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
// Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
// For printing MST follow the steps -
// 1. In one line, print an edge which is part of MST in the format -
// v1 v2 w
// where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1 <= v2 i.e. print the smaller vertex first while printing an edge.
// 2. Print V-1 edges in above format in different lines.
// Note : Order of different edges doesn't matter.


#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

//Here the cycle detection test using union find which has the worst case complexity of O(n)
//i.e linear time which is bad. we can do better by using union by rank and path compression.

class edge
{
public:
    int source;
    int dest;
    int weight;
};

bool comparator(const edge &x, const edge &y)
{
    return (x.weight < y.weight);
}

int main()
{
    int V, E;
    cin >> V >> E;

    edge *input = new edge[E];
    edge *output = new edge[V - 1];

    for (int i = 0; i < E; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        edge temp;
        temp.source = s;
        temp.dest = d;
        temp.weight = w;
        input[i] = temp;
    }

    sort(input, input + E, comparator);

    int *parent = new int[V];
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }

    int count = 0;
    int i = 0;
    while (i < V - 1)
    {
        int s = input[count].source;
        int d = input[count].dest;
        while (parent[s] != s)
        {
            s = parent[s];
        }

        while (parent[d] != d)
        {
            d = parent[d];
        }

        if (s == d)
        {
            count++;
            continue;
        }

        output[i] = input[count];
        parent[d] = s;
        count++;
        i++;
    }

    for (int i = 0; i < V - 1; i++)
    {
        edge res = output[i];
        int s, d, w;
        w = res.weight;
        if (res.source > res.dest)
        {
            d = res.source;
            s = res.dest;
        }
        else
        {
            d = res.dest;
            s = res.source;
        }

        cout << s << ' ' << d << ' ' << w << endl;
    }

    return 0;
}
