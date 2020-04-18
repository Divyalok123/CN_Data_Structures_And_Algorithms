#include <bits/stdc++.h>

using namespace std;

long profit(int *a, int t)
{
    long long int total_profit;
    total_profit = 0L;
    int max = a[t - 1];
    for (int i = t - 2; i >= 0; i--)
    {
        if (a[i] > max)
            max = a[i];
        total_profit += max - a[i];
    }
    return total_profit;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while (n--)
    {
        int t;
        cin >> t;
        int arr[t];

        for (int i = 0; i <= t - 1; i++)
        {
            cin >> arr[i];
        }

        cout << profit(arr, t) << "\n";
    }
    return 0;
}