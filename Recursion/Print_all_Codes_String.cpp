// Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.
// Note : The order of codes are not important. Just print them in different lines.

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int toint(char x)
{
    int res = x - '0';
    return res;
}

char tochar(int x)
{
    char res = x + 'a' - 1;
    return res;
}

void helper(string input, string output)
{
    if(input.size() == 0) 
    {
        reverse(output.begin(), output.end());
        cout << output << "\n";
        return;
    }
    
    helper(input.substr(1), tochar(toint(input[0])) + output);
    
    if((toint(input[0]) * 10 + toint(input[1])) >= 10 && (toint(input[0]) * 10 + toint(input[1])) <= 26)
    {
        helper(input.substr(2), tochar(toint(input[0]) * 10 + toint(input[1])) + output);
    }
    
}

void printAllPossibleCodes(string input) {
    string output = "";
    helper(input, output);
}



int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
