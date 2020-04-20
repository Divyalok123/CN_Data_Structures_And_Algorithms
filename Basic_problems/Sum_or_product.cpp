/*
Write a program that asks the user for a number N and a choice C. And then give them the possibility to choose between computing the sum and computing the product of all integers in the range 1 to N (both inclusive).
If C is equal to -
 1, then print the sum
 2, then print the product
 Any other number, then print '-1' (without the quotes)
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n;
    cin >> t;
    if(t == 1)
    {
        long long result = 0;
        for(int i = 1; i <= n; i++)
        {
            result += i;
        }
        cout << result << "\n";
    }
    else if(t == 2)
    {
        long long result = 1;
        for(int i = 1; i <= n; i++)
        {
            result *= i;
        }
        cout << result << "\n";
    }
    else cout << -1 << "\n";
    return 0;
}
