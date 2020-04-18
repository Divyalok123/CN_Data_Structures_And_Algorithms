#include <bits/stdc++.h>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    string arr1[n];
    string arr2[m];
    int num = n * m;
    string finalarr[num];
    for (int i = 0; i <= n - 1; i++)
    {
        cin >> arr1[i];
    }
    for (int j = 0; j <= m - 1; j++)
    {
        cin >> arr2[j];
    }
    int x = 0;
    for (int k = 0; k <= num - 1; k += m; int x = 0;)
    {
        for (int j = 0; j <= m - 1; j++)
        {
            finalarr[k] = arr1[x] + arr2[j];
            k++;
        }
    }
    for (int z = 0; z <= num - 1; z++)
    {
        cout << finalarr[z] << "\n";
    }

    return 0;
}