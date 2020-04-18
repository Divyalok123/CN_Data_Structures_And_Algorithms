#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;
#define NMAX 55

int DFS(int n, char cake[NMAX][NMAX], int i, int j, bool **visited)
{
    if (i < 0 || j < 0 || i >= n || j >= n || visited[i][j] || cake[i][j] != '1')
        return 0;

    visited[i][j] = true;

    int countup = DFS(n, cake, i - 1, j, visited);
    int countdown = DFS(n, cake, i + 1, j, visited);
    int countleft = DFS(n, cake, i, j - 1, visited);
    int countright = DFS(n, cake, i, j + 1, visited);

    return 1 + countup + countdown + countleft + countright;
}

int solve(int n, char cake[NMAX][NMAX])
{
    if (n == 0)
        return 0;
    if (n == 1 && cake[0][0] == 1)
        return 1;

    bool **visited = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new bool[n];
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = false;
        }
    }

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int currMax = 0;
            if (cake[i][j] == '1' && visited[i][j] == false)
            {
                currMax = DFS(n, cake, i, j, visited);
            }

            if (max < currMax)
                max = currMax;
        }
    }

    for (int i = 0; i < n; i++)
    {
        delete[] visited[i];
    }
    delete[] visited;
    return max;
}

char cake[NMAX][NMAX];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", cake[i]);
    }
    cout << solve(n, cake) << endl;
}