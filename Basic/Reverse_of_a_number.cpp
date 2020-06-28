// Write a program to generate the reverse of a given number N. Print the corresponding reverse number.

#include<iostream>
using namespace std;

int main() {
    int n, result = 0;
    cin >> n;
    while(n)
    {
        result = result*10 + n%10;
        n/=10;
    }
    cout << result;
    return 0;
}
