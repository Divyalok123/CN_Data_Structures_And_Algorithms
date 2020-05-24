// Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.

#include <iostream>
using namespace std;

#include <cstring>
#include <cmath>
int stringToNumber(char input[])
{
    if (strlen(input) == 0)
        return 0;
    int ans = input[0] - '0';
    return pow(10, strlen(input) - 1) * ans + stringToNumber(input + 1);
}

int main()
{
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
