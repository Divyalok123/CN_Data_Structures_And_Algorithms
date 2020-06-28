// Given a string, find and return the highest occurring character present in the given string.
// If there are 2 characters in the input string with same frequency, return the character which comes first.
// Note : Assume all the characters in the given string are lowercase.

#include <iostream>
using namespace std;

#include <cstring>

// input - given string
char highestOccurringChar(char input[]) {
    int arr[256] = {0};
    
    int max = arr[input[0]];
    char result = input[0];
    
    for(int i = 0; i < strlen(input); i++)
    {
        arr[input[i]]++;
    }
    int i;
    for(i = 0; i < strlen(input); i++)
    {
        if(arr[input[i]] > max)
        {
            max = arr[input[i]];
            result = input[i];
        }
    }
    
    return result;
}


int main() {
    char input[1000];
    cin.getline(input, 1000);
    cout << highestOccurringChar(input) << endl;
}
