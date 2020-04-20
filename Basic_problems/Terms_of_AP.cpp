// Write a program to print first x terms of the series 3N + 2 which are not multiples of 4.

#include<iostream>
using namespace std;

int main() {
	int n, i = 1;
    cin >> n;
    int count = 1;
    while(count <= n && i <= 2*n)
    {
        if((3*i+2)%4 != 0)
        {
            cout << (3*i + 2) << " ";
            count++;
        }
        i++;
    }
    return 0;
}
