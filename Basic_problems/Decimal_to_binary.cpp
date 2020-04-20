// Given a decimal number (integer N), convert it into binary and print.
// The binary number should be in the form of an integer.

#include<bits/stdc++.h>
using namespace std;
void binary(int n)
{
    int barr[32];
    int i = 0;
    while(n)
    {
        barr[i] = n%2;
        n /= 2;
        i++;
    }
    for(int j = i-1; j >= 0; j--)
    {
        cout << barr[j];
    }
}
int main() {
    int n;
    cin >> n;
    binary(n);
    return 0;    
}
