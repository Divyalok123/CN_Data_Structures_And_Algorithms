// Given an integer N, count and return the number of zeros that are present in the given integer using recursion.

#include <iostream>
using namespace std;


int countZeros(int n) {
    if(n == 0) return 0;
    else 
    {
        int ans = n % 10;
        n = n/10;
        if(ans == 0)
            return 1 + countZeros(n);
        else 
            return countZeros(n);
    }
}

int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}
