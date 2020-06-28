// Given a 2D integer array of size M*N, find and print the sum of ith column elements separated by space.
// Input Format :
// Line 1 : Two integers M and N (separated by space)
// Next M lines : ith row elements (separated by space)
// Output Format :
// Sum of every ith column elements (separated by space)

#include<iostream>
using namespace std;


int main(){
    int a[1000][1000];
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    
    for(int i = 0; i < m; i++)
    {
        int sum = 0;
        for(int j = 0; j < n; j++)
        {
            sum += a[j][i];
        }
        cout << sum << " ";
    }
}


