#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
//Recursive

// int LCS(string s, string t)
// {
//     if (s.size() == 0 || t.size() == 0)
//         return 0;

//     if (s[0] == t[0])
//     {
//         return 1 + LCS(s.substr(1), t.substr(1));
//     }

//     else
//     {
//         int a = LCS(s.substr(1), t);
//         int b = LCS(s, t.substr(1));
//         // int c = LCS(s.substr(1), t.substr(1));

//         return max(a, b /*max(b, c)*/);
//     }
// }

//Memoized
/*
int LCS_Memo(string s, string t, int **arr)
{
    int a = s.size();
    int b = t.size();

    if (a == 0 || b == 0)
    {
        return 0;
    }

    if (arr[a][b] != -1)
    {
        return arr[a][b];
    }

    int res;
    if (s[0] == t[0])
    {
        res = 1 + LCS_Memo(s.substr(1), t.substr(1), arr);
    }

    else
    {
        int x = LCS_Memo(s.substr(1), t, arr);
        int y = LCS_Memo(s, t.substr(1), arr);
        int z = LCS_Memo(s.substr(1), t.substr(1), arr);

        res = max(x, max(y, z));
    }
    arr[a][b] = res;
    return res;
}

int LCS(string s, string t)
{
    int a = s.size();
    int b = t.size();
    int **arr = new int *[a + 1];
    for (int i = 0; i <= a; i++)
    {
        arr[i] = new int[b + 1];
        for (int j = 0; j <= b; j++)
        {
            arr[i][j] = -1;
        }
    }

    return LCS_Memo(s, t, arr);
}
*/

//DP Solution
int LCS(string s, string t)
{
    int a = s.size();
    int b = t.size();

    int **arr = new int *[a + 1];
    for (int i = 0; i <= a; i++)
    {
        arr[i] = new int[b + 1];
        for (int j = 0; j <= b; j++)
        {
            arr[i][j] = 0;
        }
    }

    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (s[a - i] == t[b - j])
            {
                arr[i][j] = 1 + arr[i - 1][j - 1];
            }
            else
            {
                int x = arr[i - 1][j];
                int y = arr[i][j - 1];
                int z = arr[i - 1][j - 1];

                arr[i][j] = max(x, max(y, z));
            }
        }
    }

    return arr[a][b];
}

int main()
{
    string s, t;
    cin >> s >> t;

    cout << LCS(s, t) << endl;
    return 0;
}