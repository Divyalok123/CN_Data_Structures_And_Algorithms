// Given a binary number as an integer N, convert it into decimal and print.

#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int result = 0;
    cin >> s;
    int l = s.length();
    for(int i = l-1; i >= 0; i--)
    {
        if(i == l-1 && s[i] == '1')
        {
            result += 1;
        }
        else if (s[i] == '1')
        {
            result += pow(2, l-i-1);
        }
    }
    cout << result << "\n";
    
    return 0;	
}
