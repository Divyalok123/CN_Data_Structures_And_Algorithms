#include <bits/stdc++.h>
using namespace std;
#define MAXN 102

bool DFS(char edges[][MAXN], char word[], int N, int M, int i, int j, bool **visited)
{
    if (word[0] == '\0')
    {
        return true;
    }

    if (i < 0 || j < 0 || i >= N || j >= M || edges[i][j] != word[0] || visited[i][j] == true)
    {
        return false;
    }

    visited[i][j] = true;
    bool up = DFS(edges, word + 1, N, M, i - 1, j, visited);
    bool lup = DFS(edges, word + 1, N, M, i - 1, j - 1, visited);
    bool rup = DFS(edges, word + 1, N, M, i - 1, j + 1, visited);
    bool down = DFS(edges, word + 1, N, M, i + 1, j, visited);
    bool ldown = DFS(edges, word + 1, N, M, i + 1, j - 1, visited);
    bool rdown = DFS(edges, word + 1, N, M, i + 1, j + 1, visited);
    bool lside = DFS(edges, word + 1, N, M, i, j - 1, visited);
    bool rside = DFS(edges, word + 1, N, M, i, j + 1, visited);
    visited[i][j] = false;
    return up || lup || rup || down || ldown || rdown || lside || rside;
}

int solve(char Graph[][MAXN], int N, int M)
{
    char word[] = "CODINGNINJA";
    bool **visited = new bool *[N];
    for (int i = 0; i < N; i++)
    {
        visited[i] = new bool[M];
        for (int j = 0; j < M; j++)
        {
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            bool ans = false;
            if (Graph[i][j] == 'C')
            {
                ans = DFS(Graph, word, N, M, i, j, visited);
                if (ans)
                    return 1;
                for (int k = 0; k < N; k++)
                {
                    for (int l = 0; l < M; l++)
                    {
                        visited[k][l] = false;
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        delete[] visited[i];
    }
    delete[] visited;
    return 0;
}

int main()
{
    int N, M, i;
    char Graph[MAXN][MAXN];
    cin >> N >> M;
    for (i = 0; i < N; i++)
    {
        cin >> Graph[i];
    }
    cout << solve(Graph, N, M) << endl;
}