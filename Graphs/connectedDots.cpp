// Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bore and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:
// 1. These k dots are different: if i ≠ j then di is different from dj.
// 2. k is at least 4.
// 3. All dots belong to the same colour.
// 4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
// Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.

#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 51

bool DFS(char board[][MAXN], int n, int m, int i, int j, int size, bool **visited, int istart_point, int jstart_point, int iprev, int jprev)
{
    if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != board[iprev][jprev] || visited[i][j]==true)
        return false;

    if (i == istart_point && j == jstart_point && size != 1)
    {
        if (size >= 4)
            return true;
        else return false;
    }

    if (size != 1)
        visited[i][j] = true;
    
    bool ans = false;

	ans = ans || DFS(board, n, m, i - 1, j, size + 1, visited, istart_point, jstart_point, i, j);
	ans = ans || DFS(board, n, m, i + 1, j, size + 1, visited, istart_point, jstart_point, i, j);
	ans = ans || DFS(board, n, m, i, j - 1, size + 1, visited, istart_point, jstart_point, i, j);
	ans = ans || DFS(board, n, m, i, j + 1, size + 1, visited, istart_point, jstart_point, i, j);

    if(ans == false) visited[i][j] = false;
    return ans;
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
                return res;
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
	int N,M,i;
	char board[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>board[i];
	}
	cout<<solve(board,N,M)<<endl;
}