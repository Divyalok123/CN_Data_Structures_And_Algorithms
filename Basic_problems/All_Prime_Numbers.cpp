/*
Given an integer N, print all the prime numbers that lie in the range 2 to N (both inclusive).
Print the prime numbers in different lines.
*/

#include <bits/stdc++.h>
using namespace std;
void sieve(int n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for(int i = 2; i*i <= n; i++)
    {
        if(prime[i] == true)
        {
            for(int j = i*i; j <= n; j+= i){
                prime[j] = false;
            }
        }
    }
    
    for(int i = 2; i <= n; i++)
    {
        if(prime[i])
        {
            cout << i << "\n";
        }
    }
}
int main(){
    int n;
    cin >> n;
    sieve(n);
    
    return 0;
}


