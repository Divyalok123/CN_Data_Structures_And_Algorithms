#include <unordered_map>
using namespace std;

void pairSum(int *a, int n)
{
    unordered_map<int, bool> m;
    for (int i = 0; i < n; i++)
    {
        if (!m.count(a[i]))
        {
            m[a[i]] = true;
        }
        if (m.count(-a[i]))
        {
            if (a[i] < 0)
            {
                cout << a[i] << " " << -a[i] << endl;
            }
            else
            {
                cout << -a[i] << " " << a[i] << endl;
            }
        }
    }
}
