// Check Palindrome (recursive)
// Check whether a given String S is a palindrome using recursion. Return true or false.

#include <iostream>
#include <cstring>
using namespace std;

bool helper(char input[], int s, int e)
{
    if(s==e)
    {
        return true;
    }
    
    if(input[s] != input[e]) return false;
    
    if(input[s] == input[e] && s <= e) return helper(input, s+1, e-1);
    
}

bool checkPalindrome(char input[]) {
    int len = strlen(input);
    if(len == 0) return true;
    return helper(input, 0, len-1);    
}

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
