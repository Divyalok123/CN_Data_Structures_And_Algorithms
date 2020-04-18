#include <bits/stdc++.h>
using namespace std;
#define MAXN 51

bool DFS(char board[][MAXN], int n, int m, int i, int j, int size, bool **visited, int istart_point, int jstart_point, int iprev, int jprev)
{
    if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != board[iprev][jprev] || visited[i][j])
        return false;

    if (i == istart_point && j == jstart_point && size != 1)
    {
        if (size >= 4)
            return true;
        return false;
    }

    if (size != 1)
        visited[i][j] = true;

    bool up = DFS(board, n, m, i - 1, j, size + 1, visited, istart_point, jstart_point, i, j);
    bool lup = DFS(board, n, m, i - 1, j - 1, size + 1, visited, istart_point, jstart_point, i, j);
    bool rup = DFS(board, n, m, i - 1, j + 1, size + 1, visited, istart_point, jstart_point, i, j);
    bool down = DFS(board, n, m, i + 1, j, size + 1, visited, istart_point, jstart_point, i, j);
    bool ldown = DFS(board, n, m, i + 1, j - 1, size + 1, visited, istart_point, jstart_point, i, j);
    bool rdown = DFS(board, n, m, i + 1, j + 1, size + 1, visited, istart_point, jstart_point, i, j);
    bool lside = DFS(board, n, m, i, j - 1, size + 1, visited, istart_point, jstart_point, i, j);
    bool rside = DFS(board, n, m, i, j + 1, size + 1, visited, istart_point, jstart_point, i, j);

    if ((up || lup || rup || down || ldown || rdown || lside || rside) != 1)
    {
        visited[i][j] = false;
        return false;
    }
    return true;
}

int solve(char board[][MAXN], int n, int m)
{
    bool **visited = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new bool[m];
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = false;
        }
    }

    bool res = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            res = DFS(board, n, m, i, j, 1, visited, i, j, i, j);
            if (res)
                break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        delete[] visited[i];
    }

    delete[] visited;

    return res;
}

int main()
{
    int N, M, i;
    char board[MAXN][MAXN];
    cin >> N >> M;
    for (i = 0; i < N; i++)
    {
        cin >> board[i];
    }
    cout << solve(board, N, M) << endl;
}